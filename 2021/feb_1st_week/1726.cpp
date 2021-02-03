#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define vec2d std::vector<std::vector<bool>>
int dy[4] = { 0,0,1,-1 }, dx[4] = { 1,-1,0,0 };
bool ck[100][100][4];

struct Robot {
	int y, x, d,c=0;
	Robot() {};
	Robot(const int& yy, const int& xx, const int& dd, const int& cc) {
		y = yy, x = xx, d = dd,c=cc;
	}
};

int turn(int d, const int& t) {
	if (d == 0)
	{
		if (t == 1) return 2;
		else return 3;
	}
	else if (d == 1) {
		if (t == 1) return 3;
		else return 2;
	}
	else if (d == 2) {
		if (t == 1) return 1;
		else return 0;
	}
	else {
		if (t == 1) return 0;
		else return 1;
	}
}

bool check(Robot& bb, Robot& dst) {
	if (bb.y == dst.y && bb.x == dst.x&& bb.d == dst.d) return true;
	return false;
}

int main() {
	int m, n; std::cin >> m >> n;
	vec2d wall(m, std::vector<bool> (n, 0));
	Robot start, dst;
	std::queue<Robot> Q;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			int num; std::cin >> num;
			wall[i][j]=num;
		}
	
	std::cin >> start.y >> start.x >> start.d;
	std::cin >> dst.y >> dst.x >> dst.d;
	start.y -= 1; start.x -= 1; start.d -= 1; dst.y -= 1; dst.x -= 1; dst.d -= 1;
	ck[start.y][start.x][start.d]=1;
	Q.push(start);
	while (!Q.empty()) {
		Robot now = Q.front();
		if (check(now, dst)) {
			std::cout << now.c<< '\n';
			return 0;
		}
		Q.pop();
		int ndy = dy[now.d], ndx = dx[now.d];
		for (int gk = 1; gk <= 3; gk++) {
			int ny = now.y + ndy*gk, nx = now.x + ndx*gk;
			if (ny < 0 || nx < 0 || ny >= m || nx >= n || ck[ny][nx][now.d]) continue;
			if (wall[ny][nx]) break;
			ck[ny][nx][now.d] = 1;
			Q.push(Robot(ny, nx, now.d, now.c + 1));
		}
		int pd = turn(now.d, 1), nd = turn(now.d, -1);
		if (!ck[now.y][now.x][pd]) {
			ck[now.y][now.x][pd]=1;
			Q.push(Robot(now.y, now.x, pd, now.c + 1));
		}
		if (!ck[now.y][now.x][nd]) {
			ck[now.y][now.x][nd] = 1;
			Q.push(Robot(now.y, now.x, nd, now.c + 1));
		}
	}

	return 0;
}