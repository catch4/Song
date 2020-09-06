/*
Catch study 14주차
백준_새로운 게임
https://www.acmicpc.net/problem/17780
*/
/*-----------------
틀렸떤 이유
- 빨간색 이동 잘못이해함
맨 처음에 빨간색은 뒤로 입력해야 하는줄 알고 deque 사용했었음 push_back만 쓸거면 vector 쓸걸

풀이
1. 각 맵마다 현재 존재하는 말 번호 저장
2. 말의 번호 마다 위치값 저장
3. 나머지 구현
-----------------*/
#include <iostream>
#include <vector>
#include <deque>
#define pi std::pair<int,int>

struct Pos {
	int y, x, d;
};
int n, k, map[12][12], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };
std::deque<int> posmap[12][12]; // 1.
std::vector<Pos> pos; // 2.

bool simul() {
	for (int i = 0; i<k; i++) {
		int y = pos[i].y, x = pos[i].x, d = pos[i].d;

		if (posmap[y][x].back() != i) continue;
		int ny = y + dy[d], nx = x + dx[d];
		// 파랑
		if (ny<0 || ny >= n || nx<0 || nx >= n || map[ny][nx] == 2) {
			pos[i].d = (1 - (d % 2)) + (d / 2) * 2;
			d = pos[i].d;
			ny = y + dy[d], nx = x + dx[d];
		}
		// 파랑 이후 파랑
		if (map[ny][nx] == 2 || ny<0 || ny >= n || nx<0 || nx >= n)
			continue;
		else if (!map[ny][nx]) { // 흰색
			for (int j = posmap[y][x].size() - 1; j >= 0; j--)
			{
				posmap[ny][nx].push_front(posmap[y][x][j]);
				pos[posmap[y][x][j]].y = ny, pos[posmap[y][x][j]].x = nx;
			}
			posmap[y][x].clear();
		}
		else if (map[ny][nx] == 1) { // 빨강
			for (int j = 0; j<posmap[y][x].size(); j++) {
				posmap[ny][nx].push_front(posmap[y][x][j]);
				pos[posmap[y][x][j]].y = ny, pos[posmap[y][x][j]].x = nx;
			}
			posmap[y][x].clear();
		}
		if (posmap[ny][nx].size() >= 4) return true; // 성공 조건
	}
	return false;
}

int main() {
	std::cin >> n >> k;
	pos.resize(k);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			std::cin >> map[i][j];

	for (int i = 0; i<k; i++) {
		int cy, cx, cd; std::cin >> cy >> cx >> cd;
		pos[i].y = cy - 1, pos[i].x = cx - 1; pos[i].d = cd - 1;
		posmap[cy - 1][cx - 1].push_back(i);
	}

	for (int i = 0; i<1000; i++)
		if (simul()) {
			std::cout << i + 1 << '\n';
			return 0;
		}
	std::cout << -1 << '\n';
	return 0;
}