/*
Catch study 31/mar/4week
백준_1800 인터넷 설치
https://www.acmicpc.net/problem/1800
다익스트라, 이분탐색
가격을 이분탐색하며 해당 가격을 넘는게 k개 보다 적은 경우 true
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define pi std::pair<int,int>

int n, p, k, answer = -1;
bool dij(std::vector<std::vector<pi>>& cable,
	std::vector<int> dist,int c) {
	std::priority_queue<pi> Q; 
	Q.push({ 0, 1 });
	dist[1] = 0;
	while (Q.size()) {
		int now = Q.top().second;
		int cost = -Q.top().first;
		Q.pop();
		if (dist[now] < cost) continue;
		for (int i = 0; i < cable[now].size();i++) {
			pi p = cable[now][i];
			int nxt = p.first;
			int nxtCost = cost + (p.second > c);
			if (nxtCost < dist[nxt]) {
				dist[nxt] = nxtCost;
				Q.push({ -nxtCost, nxt });
			}
		}
	}

	return dist[n] <= k;
}

int main() {
	std::cin >> n >> p >> k;
	std::vector<int> dist(n + 1,2147000000);
	std::vector<std::vector<pi>> cable(n + 1);
	for (int i = 0; i < p; i++) {
		int s, e, c; std::cin >> s >> e >> c;
		cable[s].push_back({ e,c });
		cable[e].push_back({ s,c });
	}
	int l = 0, r = 1000000;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (dij(cable, dist, mid)) {
			answer = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	std::cout << answer << '\n';
}