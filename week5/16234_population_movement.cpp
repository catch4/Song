/*
Catch study 5주차
백준_16234 인구 이동
https://www.acmicpc.net/problem/16234
*/
/*---------------------------
풀이
vecs_N를 초기화 안해주고 parent 초기화 안해줘서 틀렸음
union, find 사용해서 풀었음.

1. Node class는 처음에 child로 자기자신, parent도 자기자신
2. 조건에 부합하면 union, 이 때 parent 최신화 하고 parent(a)의 자식에
   b의 자식들 추가
3. 합 구하는 과정에서 중복 피하기 위해서 class 내부 num은 map에 있는 값으로
   덧셈
4. 바뀐 map에 대해 node 갱신

---------------------------*/
#include<iostream>
#include<vector>
#include<map>
#define pi std::pair<int,int>
#define vecs std::vector<std::vector<int>>
#define y first
#define x second

int n, Min, Max, cnt = 0, dy[2] = { 1,0 }, dx[2] = { 0,1 };

struct Node { //1.
	pi parent;
	std::vector<pi> child;
	int num = 0;
	void get(const int& n_num,const int&i, const int&j)
	{
		num = n_num;
		parent = { i,j };
		child.push_back({ i,j });
	}
};

#define vecs_N std::vector<std::vector<Node>>

pi Find(vecs_N& p, pi& ch)
{
	if (p[ch.y][ch.x].parent.y == ch.y&&p[ch.y][ch.x].parent.x == ch.x)
		return ch;
	else return p[ch.y][ch.x].parent = Find(p, p[ch.y][ch.x].parent);
}

void Uni(vecs& map, vecs_N& p, const pi& a, const pi&b) // 2,3.
{
	pi ap = Find(p,p[a.y][a.x].parent);
	pi bp = Find(p,p[b.y][b.x].parent);
	if (ap.y == bp.y&&ap.x == bp.x) return;
	p[bp.y][bp.x].parent = ap;
	std::map<pi, bool> mp;
	for (int i = 0; i < p[ap.y][ap.x].child.size(); i++)
		mp[p[ap.y][ap.x].child[i]] = 1;
	for (int i = 0; i<p[bp.y][bp.x].child.size(); i++)
		if (!mp[p[bp.y][bp.x].child[i]]) {
			p[ap.y][ap.x].child.push_back(p[bp.y][bp.x].child[i]);
			// 3.
			p[ap.y][ap.x].num += map[p[bp.y][bp.x].child[i].y][p[bp.y][bp.x].child[i].x];
		}
}

void movement(vecs& map, vecs_N& p) {
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			if (i == p[i][j].parent.y &&
				j == p[i][j].parent.x) {
				int n_num = p[i][j].num / p[i][j].child.size();
				std::vector<pi>& ch = p[i][j].child;
				for (int z = 0; z < ch.size(); z++)
					map[ch[z].y][ch[z].x] = n_num;
			}
}

void init(vecs& map, vecs_N& p) { // 4.
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			p[i][j].child.clear();
			p[i][j].get(map[i][j], i, j);
		}
}

bool bound(vecs& map, vecs_N& p) {
	bool flag = false;
	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++)
			for (int z = 0; z < 2; z++)
			{
				int n_y = i + dy[z], n_x = j + dx[z];
				if (n_x < n && n_y<n)
				{
					int diff = abs(map[i][j] - map[n_y][n_x]);
					if (diff >= Min&&diff <= Max)
					{
						Uni(map, p, { i,j }, { n_y ,n_x }); // 2.
						flag = true;
					}
				}
			}
	if (!flag) return false;
	movement(map, p);
	init(map, p);
	return true;
}

int main() {
	std::cin >> n >> Min >> Max;
	vecs map(n, std::vector<int>(n));
	vecs_N p(n, std::vector<Node>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			std::cin >> map[i][j];
			p[i][j].get(map[i][j],i, j);
		}
	while (bound(map, p)) cnt++;
	std::cout << cnt << std::endl;
}
