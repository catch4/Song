/*
Catch study 5����
����_16234 �α� �̵�
https://www.acmicpc.net/problem/16234
*/
/*---------------------------
Ǯ��
vecs_N�� �ʱ�ȭ �����ְ� parent �ʱ�ȭ �����༭ Ʋ����
union, find ����ؼ� Ǯ����.

1. Node class�� ó���� child�� �ڱ��ڽ�, parent�� �ڱ��ڽ�
2. ���ǿ� �����ϸ� union, �� �� parent �ֽ�ȭ �ϰ� parent(a)�� �ڽĿ�
   b�� �ڽĵ� �߰�
3. �� ���ϴ� �������� �ߺ� ���ϱ� ���ؼ� class ���� num�� map�� �ִ� ������
   ����
4. �ٲ� map�� ���� node ����

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
