/*
Catch study 7����
����_2151 �ſ� ��ġ
https://www.acmicpc.net/problem/2151
*/
/*
Ʋ������
���� �߸��Ǽ� �ð��ʰ����ǵ� map���� üũ�ϴ� �� �߰��ϰ� �־���

dfs�� Ǯ���� bfs�� Ǫ�°� �� ���� �� ���Ƽ� bfs�� �ٽ� ǰ
����� bfs�� �޸�, �ӵ� �鿡�� ����

Ǯ��
������ ���� x�� �������� ���� �� y������ ���� �������ϰ�
y�� �������� ������ x�� �������� ���� �������ϴ� �κи� �Ű澲�� ��

*/

//-----------------------------------dfs----------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#define vec2d_c std::vector<std::vector<char>>
#define pi std::pair<int,int>
#define y first
#define x second
std::vector<pi> mirr;
std::vector<pi> pos;
int n, min=2147000000;

bool check_wall(vec2d_c& map,pi& src, pi& dst, const bool& axis)
{
	if (!axis)
	{
		for (int i = std::min(src.y, dst.y) + 1; i < std::max(src.y, dst.y); i++)
			if (map[i][src.x] == '*') return false;
	}
	else
		for (int i = std::min(src.x, dst.x) + 1; i < std::max(src.x, dst.x); i++)
			if (map[src.y][i] == '*') return false;
	return true;
}


void dfs(vec2d_c& map, std::vector<bool>& ck,pi& now,const int& cnt,const bool& axis) {
	if (min <= cnt) return;
	
	if (axis && now.y == pos[1].y&&check_wall(map, now, pos[1], axis)) min = cnt;
	else if (!axis && now.x == pos[1].x&& check_wall(map, now, pos[1], axis)) min = cnt;
	else {
		for (int i = 0; i < mirr.size(); i++)
		{
			if (axis)
			{
				if (!ck[i] && (mirr[i].y == now.y))
				{
					if (check_wall(map, now, mirr[i], axis))
					{
						ck[i] = 1;
						dfs(map, ck, mirr[i], cnt + 1, 0);
						ck[i] = 0;
					}
				}
			}
			else {
				if (!ck[i] && (mirr[i].x == now.x))
				{
					if (check_wall(map, now, mirr[i], axis))
					{
						ck[i] = 1;
						dfs(map, ck, mirr[i], cnt + 1, 1);
						ck[i] = 0;
					}
				}
			}
		}
	}
}

int main() {
	std::cin >> n;
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::vector<std::vector<char>> map(n, std::vector<char>(n, 0));	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == '!') mirr.push_back({ i,j });
			else if (map[i][j] == '#') pos.push_back({ i,j });
		}
	std::vector<bool> ck(mirr.size());
	dfs(map, ck, pos[0], 0, 0);
	dfs(map, ck, pos[0], 0, 1);
	std::cout << min << '\n';
	return 0;
}

//-----------------------------------bfs----------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#define y first
#define x second
#define pi std::pair<int,int>
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };

struct Pos {
	pi p;
	bool d=false;
	int cnt=0;
	Pos() {}
	Pos(const pi& t_p,const bool& t_d,const int& t_cnt)
	{
		p = t_p, d = t_d, cnt = t_cnt;
	}
};
int main() {
	int n; std::cin >> n;
	std::vector<std::vector<char>> map(n, std::vector<char>(n, 0));
	std::vector<std::vector<bool>> ck(n, std::vector<bool>(n, 0));
	std::queue<Pos> Q;
	pi start;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			std::cin >> map[i][j];
			if (map[i][j] == '#')
			{
				start.y = i;
				start.x = j;
			}
		}
	Q.push(Pos(start, 0, 0));
	Q.push(Pos(start, 1, 0));
	ck[start.y][start.x] = 1;
	while (!Q.empty()) {
		Pos now = Q.front();
		Q.pop();
		for (int k = int(now.d) * 2; k < (int(now.d) + 1) * 2; k++)
		{
			int n_y = now.p.y,n_x = now.p.x;
			while (1) {
				n_y += dy[k], n_x += dx[k];
				if (n_y < 0 || n_x < 0 || n_y >= n || n_x >= n || map[n_y][n_x] == '*') break;
				if (!ck[n_y][n_x])
				{
					if (map[n_y][n_x] == '#') {
						std::cout << now.cnt << '\n';
						return 0;
					}
					else if (map[n_y][n_x] == '!')
					{
						ck[n_y][n_x] = 1;
						Q.push(Pos({ n_y,n_x, }, 1 - int(now.d), now.cnt + 1));
					}
				}
			}
		}
	}
	return 0;
}