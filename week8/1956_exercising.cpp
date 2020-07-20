/*
Catch study 8주차
백준_1956 운동
https://www.acmicpc.net/problem/1956
*/
/*-----------------------------
틀렸던이유
"불가능할 시 -1을 출력한다" 빼먹음

풀이
플로이드 와샬로 품

1. 각각 비용 최신화
2. 출발지로 돌아온 경우 answer 최신화
------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147000000
int n,m,answer=INF;

int main() {
	std::cin >> n>>m;
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::vector<std::vector<int>> min_c(n, std::vector<int>(n, INF));
	for (int i = 0; i < m; i++) {
		int a, b, c; std::cin >> a >> b >> c;
		min_c[a - 1][b - 1] = c;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				if (min_c[i][j] == INF || min_c[j][k] == INF) continue;
				min_c[i][k] = std::min(min_c[i][k], min_c[i][j] + min_c[j][k]); // 1.
				if (i == k) answer = std::min(answer,min_c[i][k]); // 2.
			}
	if (answer == INF) std::cout << -1 << '\n';
	else std::cout << answer << '\n';
	return 0;
}