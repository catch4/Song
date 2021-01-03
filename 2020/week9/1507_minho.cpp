/*
Catch study 9주차
백준_궁금한 민호
https://www.acmicpc.net/problem/1507
*/
/*-----------------
틀렸던 이유
1. 42 line을 안해서 한쪽 다리만 갱신되는 경우가 있었음

풀이
1. 놓여진 다리를 우선순위 큐에 넣는다.
2. 하나씩 다리를 놓으며 다익스트라를 돌리고
   맨처음 입력값과 동일한지 확인한다.
3. 동일할 경우 놓여진 다리를 합한다.
-----------------*/

#include <iostream>
#include <vector>
#include <queue>
#define INF 2147000000
#define pi std::pair<int,int>
#define vec_2d std::vector<std::vector<int>>
int n;

struct Info {
	int c, y, x;
	Info() {}
	Info(const int& t_c, const int& t_y, const int& t_x) {
		c = t_c, y = t_y, x = t_x;
	}
	bool operator<(const Info& bb)const {
		return c > bb.c;
	}
};

bool check(vec_2d& tmp, vec_2d& mp) { // 2.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i == k || tmp[i][j] == INF || tmp[j][k] == INF) continue;
				tmp[i][k] = std::min(tmp[i][k], tmp[i][j] + tmp[j][k]);
				tmp[k][i] = tmp[i][k];
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (tmp[i][j] != mp[i][j]) return false; // 2.

	return true; // 2.
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n;
	vec_2d mp(n, std::vector<int>(n, 0));
	vec_2d tmp(n, std::vector<int>(n, INF));
	std::priority_queue<Info> Q;
	int sum = 0;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> mp[i][j];
			if (i == j) tmp[i][j] = 0;
			else if (i < j) Q.push(Info(mp[i][j], i, j)); // 1.
			else if (mp[i][j]) {
				flag = true;
			}
		}
	}
	if (n == 1 || !flag) {
		std::cout << 0 << '\n';
		return 0;
	}
	while (!Q.empty()) {
		Info now = Q.top();
		Q.pop();
		if (tmp[now.y][now.x] > now.c || tmp[now.x][now.y]>now.c) {
			sum += now.c;
			tmp[now.y][now.x] = now.c;
			tmp[now.x][now.y] = now.c;
			if (check(tmp, mp)) { // 3.
				std::cout << sum << '\n';
				flag = false;
				break;
			}
		}
	}
	if (flag) std::cout << -1 << '\n';
	return 0;
}