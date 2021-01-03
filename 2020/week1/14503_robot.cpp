/*
Catch study 1주차
백준_14503 로봇청소기
https://www.acmicpc.net/problem/14503
*/
#include <iostream>
#include <vector>

int main() {
	int n, m,d,n_d,y,x,cnt=1,rot_cnt=0; 

	// 북동남서
	int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };

	std::cin >> n >> m>>y>>x>>d;
	std::vector<std::vector<int>> ck(n, std::vector<int>(m,0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> ck[i][j];
	ck[y][x] = 2;

	while (1)
	{
      // 4번 회전 한 경우
		if (rot_cnt == 4)
		{
			int n_d = (d + 2) % 4;
			int n_y = y + dy[n_d], n_x = x + dx[n_d];
          // 뒤에 벽이거나 막힌 경우 while문 탈출
			if (n_y < 0 || n_y >= n || n_x < 0 || n_x >= m || ck[n_y][n_x] == 1) break;
			y = n_y;
			x = n_x;
			rot_cnt = 0;
			continue;
		}
      // 왼쪽 방향
		if (!d) d = 3;
		else d -= 1;
		int n_y = y + dy[d], n_x = x + dx[d];
		
		// 왼쪽이 청소 불가능한 경우
		if (n_y < 0 || n_y >= n || n_x < 0 || n_x >= m || ck[n_y][n_x])
			rot_cnt++;
		else // 왼쪽이 청소 가능한 경우
		{
			rot_cnt = 0;
			ck[n_y][n_x] = 2;
			cnt++;
			y = n_y;
			x = n_x;
		}
	}
	std::cout << cnt;

	return 0;
}
