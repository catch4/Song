/*
Catch study 21/jan/2week
백준_케잌 배달
https://www.acmicpc.net/problem/2159
*/
/*-----------------
풀이
인접한 4개의 좌표에 도달하기 위한 최소값 최신화 하면서 진행
-----------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#define pi std::pair<int,int>

int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };

struct Info {
	std::vector < pi > pos;
	std::vector < long long > c;
	void cin() {
		pos.resize(4);
		c.resize(4);
		std::cin >> pos[0].first >> pos[0].second;
		for (int i = 1; i < 4; i++)
			pos[i] = pos[0];
	}
	void update(pi& dst) {
		std::vector<pi> n_pos(4);
		std::vector<long long> nc(4, LLONG_MAX);
		for (int i = 0; i < 4; i++) {
			int y = dy[i] + dst.first, x = dx[i] + dst.second;			
			for (int j = 0; j < 4; j++) {
				nc[i] = std::min(nc[i], abs(pos[j].first - y) + abs(pos[j].second - x) + c[j]);
			}
			n_pos[i] = { y,x };
		}
		pos = n_pos;
		c = nc;
		
	}
};

int main() {
	long long answer = LLONG_MAX;
	int n; std::cin >> n;
	Info src;
	pi dst;
	src.cin();
	
	for (int i = 0; i < n; i++) {
		std::cin >> dst.first >> dst.second;
		src.update(dst);
	}
	for (int i = 0; i < 4; i++) answer = std::min(answer, src.c[i]);
	std::cout << answer << '\n';

}