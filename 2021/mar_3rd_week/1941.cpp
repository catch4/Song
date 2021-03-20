/*
Catch study 17/mar/3week
백준_1941 소문난 칠공주
https://www.acmicpc.net/problem/1941

비트 마스크로 방문 체크, 브루트 포스
*/

#include <iostream>
#include <vector>
#include <queue>
const int N = 5;
char mp[25][25];
bool ck[1 << 25];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 },answer=0;

struct Info {
	int cnt=0,Y_cnt=0,p=0;
	Info() {}
	Info(const int& cc, const int& yc, const int& pos) { Y_cnt = yc; cnt = cc; p = pos; }
};

int main() {
	
	std::queue<Info> Q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			std::cin >> mp[i][j];
			int pos = 1 << (i * 5 + j);
			if (mp[i][j] == 'Y')
				Q.push(Info(1, 1, 1 << (i * 5 + j)));
			else
				Q.push(Info( 1, 0, 1 << (i * 5 + j)));
			ck[1 << (i * 5 + j)] = 1;
		}

	while (!Q.empty()) {
		Info now = Q.front();
		Q.pop();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (!(now.p&(1 << (i*N + j)))) continue;
				for (int z = 0; z < 4; z++) {
					int y = i + dy[z], x = j + dx[z];
					if (x < 0 || x >= N || y < 0 || y >= N) continue;

					int np = now.p | (1 << (y * 5 + x));
					if (ck[np]) continue;
					ck[np] = 1;
					if (now.Y_cnt == 3 && mp[y][x] == 'Y') continue;

					if (now.cnt == 6) {
						answer += 1;
					}
					else
						Q.push(Info(now.cnt + 1, mp[y][x] == 'Y' ? now.Y_cnt + 1 : now.Y_cnt, np));
				}
			}
	}
	std::cout << answer << '\n';


	return 0;
}