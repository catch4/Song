/*
Catch study 4주차
백준_2178 미로 탐색
https://www.acmicpc.net/problem/2178
*/
#include <iostream>
#include <vector>
#include <queue>
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

int main() {
	int n, m; std::cin >> n >> m;
	std::vector<std::vector<char>> maze(n, std::vector<char>(m, 0));
	std::vector<std::vector<int>> ret(n, std::vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> maze[i][j];
	std::queue<std::pair<int, int>> Q;
	ret[0][0] = 1;
	Q.push({ 0,0 });
	while (!Q.empty())
	{
		std::pair<int, int> now = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i], nx = now.second + dx[i];
			if (ny == n - 1 && nx == m - 1) {
				std::cout << ret[now.first][now.second] + 1 << std::endl;
				return 0;
			}
			if (ny >= 0 && ny < n&&nx >= 0 && nx < m && !ret[ny][nx] && maze[ny][nx] == '1')
			{
				ret[ny][nx] = ret[now.first][now.second] + 1;
				Q.push({ ny,nx });
			}
		}
	}
}