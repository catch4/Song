/*
Catch study 17/mar/3week
백준_2665 미로만들기
https://www.acmicpc.net/problem/2665

우선순위 큐 사용.
*/
#include <iostream>
#include <vector>
#include <queue>
#define vec2d_b std::vector<std::vector<bool>>
struct Info {
	int y, x, c = 0;
	Info() {}
	Info(const int& yy, const int& xx, const int& cc) {
		y = yy, x = xx, c = cc;
	}
	const bool operator < (const Info& bb) const {
		return c > bb.c;
	}
};
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int main() {
	int n; std::cin >> n;
	vec2d_b mp(n, std::vector<bool>(n, 0)),ck(n, std::vector<bool>(n, 0));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char is_wh;	std::cin >> is_wh;
			mp[i][j] = is_wh - '0';
		}
	std::priority_queue<Info> Q;
	Q.push(Info(0, 0, 0));
	ck[0][0] = 1;
	while (!Q.empty()) {
		Info now = Q.top();
		Q.pop();
		if (now.y == n - 1 && now.x == n - 1) {
			std::cout << now.c << '\n';
			break;
		}
		for (int z = 0; z < 4; z++) {
			int ny = now.y + dy[z], nx = now.x + dx[z];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n || ck[ny][nx]) continue;
			ck[ny][nx] = 1;
			if (mp[ny][nx])
				Q.push(Info(ny, nx, now.c));
			else
				Q.push(Info(ny, nx, now.c + 1));			
		}
	}
	return 0;
}