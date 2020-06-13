/*
Catch study 2주차
백준_1916 최소비용
https://www.acmicpc.net/problem/1916
*/

/*
풀이

틀린이유
맨 처음 단순 dfs로 풀었을 때 시간초과
-> 다익스트라 알고리즘 사용

0. 선언한 INF 값으로 초기화
1. 다익스트라
	1-1. start 마을에 해당하는 비용은 0으로 초기화
	1-2. 현재 start 마을에서 nxt로 가는 비용보다 
		 start 마을에서 cur마을로 가는 비용 + cur마을에서 nxt로 가는 비용이
		 더 저렴할 경우 해당 비용으로 변경 및 우선순위 큐에 push.
	1-3. 비용이 INF일 경우 오버플로우가 날 수 있으므로 처리하지 않고 pop만
	1-4. 큐가 빌 때까지 반복
*/

#include <iostream>
#include <queue>
#include <vector>
#define ll long long
struct node {
	int to;
	ll weight;
	bool operator<(const node &bb) const {
		return weight > bb.weight;
	}
};

const ll INF = (ll)2147000000;
ll dist[1000];
std::vector<node> bus[1000];
int n, m,start,dst;

ll dijkstra(int start,int dst)
{
	std::priority_queue<node> pq;
	// 1-1.
	pq.push({ start, 0 });
	dist[start] = 0;
	// 1-1.

	// 1-4.
	while (!pq.empty())
	{
		node cur = pq.top();
		pq.pop();
		if (cur.weight > dist[cur.to])
			continue;
		for (node &nxt : bus[cur.to])
		{
			// 1-3.
			if (nxt.weight == INF) continue; 
			// 1-3.
			// 1-2.
			if (dist[cur.to] + nxt.weight < dist[nxt.to])
			{
				dist[nxt.to] = dist[cur.to] + nxt.weight;
				pq.push({ nxt.to, dist[nxt.to] });
			}
			// 1-2.
		}
	}
	// 1-4.
	return dist[dst];
}

int main()
{
	std::cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, d, w;
		std::cin >> s >> d >> w;
		bus[s - 1].push_back({ d - 1, w });
	}
	// 0.
	std::fill(dist,dist+1000, INF);
	// 0.
	std::cin >> start >> dst;
	std::cout << dijkstra(start-1, dst-1);
	return 0;
}