/*
Catch study 21/feb/1week
백준_불
https://www.acmicpc.net/problem/5427
*/
/*-----------------
풀이
불과 상근이의 위치를 따로 bfs
-----------------*/

#include <iostream>
#include <vector>
#include <queue>

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
struct Info {
	int y = 0, x = 0, cnt=0;
	Info() {}
	Info(const int& i, const int& j, const int& c) {
		y = i, x = j, cnt=c;
	}
};

int main() {
	int t; std::cin >> t;
	while (t--) {
		int m, n,answer=2147000000,iter=0; std::cin >> m >> n;
		std::vector<std::vector<char>> mp(n, std::vector<char>(m, 0));
		std::vector<std::vector<bool>> ck(n, std::vector<bool>(m, 0));

		std::queue<Info> Qf,Q;
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				std::cin >> mp[i][j];
				if (mp[i][j] == '@') {
					Q.push(Info(i, j, 0));
					mp[i][j] = '.';
					ck[i][j] = 1;
				}
				else if (mp[i][j] == '*') 
					Qf.push(Info(i, j, 0));
			}

		while (!Q.empty()) {
			Info now = Q.front();
			if (now.x == 0 || now.x == m-1 || now.y == 0 || now.y == n-1) {
				answer = now.cnt + 1;
				break;
			}
			Q.pop();
			if (iter == now.cnt) {
				iter += 1;
				while (!Qf.empty() && Qf.front().cnt < iter) {
					Info nowf = Qf.front();
					Qf.pop();
					for (int z = 0; z < 4; z++) {
						int ny = nowf.y + dy[z], nx = nowf.x + dx[z];
						if (ny < 0 || ny >= n || nx < 0 || nx >= m || mp[ny][nx]!='.') continue;
						mp[ny][nx] = '*';
						Qf.push(Info(ny, nx, nowf.cnt + 1));
					}
				}
			}

			for (int z = 0; z < 4; z++) {
				int ny = now.y + dy[z], nx = now.x + dx[z];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m || mp[ny][nx] != '.'|| ck[ny][nx]) continue;
				Q.push(Info(ny, nx, now.cnt + 1));
				ck[ny][nx] = 1;
			}
		}
		if (answer == 2147000000)
			std::cout << "IMPOSSIBLE\n";
		else
			std::cout << answer << '\n';
	}
}
