/*
Catch study 12주차
백준_배열에서 이동
https://www.acmicpc.net/problem/1981
*/
/*-----------------
풀이 - 틀려서 아이디어만 블로그에서 참고

1. 차이 값으로 이분탐색
2. 최소값부터 가능한지 탐색 (BFS)

-----------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pi std::pair<int,int>
int n, Min = 2147000000, Max = -2147000000, map[100][100], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

bool dfs(const int& mid) { //2.
	for (int i = Min; i <= Max; i++) {
		if (map[0][0]<i || map[0][0]>i + mid) continue;
		std::queue<pi> Q;
		Q.push({ 0,0 });
		bool ck[100][100] = { 0, };
		ck[0][0] = 1;
		while (!Q.empty()) {
			pi now = Q.front();
			Q.pop();

			for (int k = 0; k < 4; k++) {
				int y = now.first + dy[k], x = now.second + dx[k];
				if (y < 0 || y >= n || x < 0 || x >= n || ck[y][x] || map[y][x]<i || map[y][x]>i + mid) continue;
				if (y == n - 1 && x == n - 1)
					return true;
				ck[y][x] = 1;
				Q.push({ y,x });
			}
		}
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			std::cin >> map[i][j];
			Max = std::max(Max, map[i][j]);
			Min = std::min(Min, map[i][j]);
		}
	int l = 0, r = Max - Min, result = r; 
	while (l <= r) { // 1.
		int mid = (l + r) / 2;
		if (dfs(mid))
		{
			result = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	std::cout << result << '\n';
}