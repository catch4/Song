/*
Catch study 4����
����_17244 �Ƹ´� ���
https://www.acmicpc.net/problem/17244
*/
/*---------------------------
Ǯ��
X ȹ���ϴ� ������ dfs, ȹ���ϴ� ������ bfs�� ������

1. map���� ��(#) Ȥ�� ��(.)�� ����
2. ��ġ ���� ����,��, X�� ����
3. dfs �������� �Ź� ������ �ٸ�, 
   �Ѱ��� ���� �������� �������� �Ѱ���
4-1. �Ϲ����� bfs
4-2. �������� �����ϸ� �ٷ� �̵� Ƚ�� �Ѱ���
5. �ּҰ� �ֽ�ȭ
---------------------------*/
#include <iostream>
#include <vector>
#include <queue>
#define pi std::pair<int,int>
#define pii std::pair<pi,int>
#define vecs_c std::vector<std::vector<char>>
#define vecs_b std::vector<std::vector<bool>>
#define y first
#define x second
int n, m, min = 2147000000, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

int move(vecs_c& map,pi& start, pi& end) { // 4-1.
	std::queue<pii> Q;
	vecs_b ck(n, std::vector<bool>(m));
	ck[start.y][start.x] = 1;
	Q.push({{ start.y,start.x },0 });
	while (!Q.empty())
	{
		pi pos = Q.front().first;
		int cost = Q.front().second;
		Q.pop();
		for (int k = 0; k < 4; k++)
		{
			int ny = pos.y + dy[k], nx = pos.x + dx[k];
			if (ny >= 0 && ny < n&&nx >= 0 && nx < m && !ck[ny][nx] && map[ny][nx] != '#')
				if (ny == end.y&&nx == end.x) return cost + 1; // 4-2.
				else {
					ck[ny][nx] = 1;
					Q.push({ {ny,nx},cost + 1 });
				}
		}
	}
}

void dfs(vecs_c& map,pi& start,pi& end,std::vector<pi>& X,
	const int& choiced,std::vector<bool>& ck,const int& sum) {
	if (choiced == X.size())
	{
		int n_sum = sum + move(map,start, end);
		if (n_sum < min) min = n_sum; // 5.
	}
	else {
		for (int i = 0; i < X.size(); i++)
		{
			if (!ck[i])
			{
				ck[i] = 1;
				// 3.
				dfs(map, X[i], end, X, choiced + 1, ck, sum + move(map, start, X[i]));
				ck[i] = 0;
			}
		}
	}
}

int main(){
	std::cin >> m >> n;
	vecs_c map(n, std::vector<char>(m));
	pi start, end;
	std::vector<pi> X;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			// 2.
			char tmp; std::cin >> tmp;
			if (tmp == 'S') start = { i,j };
			else if (tmp == 'E') end = { i,j };
			else if (tmp == 'X') X.push_back({ i,j });
			// 2.
			
			// 1.
			if (tmp != '#') map[i][j] = '.';
			else map[i][j] = '#';
			// 1.
		}
	}
	std::vector<bool> ck(X.size(), 0);
	dfs(map, start, end, X, 0, ck, 0);
	std::cout << min << '\n';
	return 0;
}
