/*
Catch study 13주차
백준_5719 거의 최단 경로
https://www.acmicpc.net/problem/5719
*/
/*-----------------
틀렸던 이유
clear 제대로 안해줘서 메모리 초과

풀이
1. 현재 최단 거리를 삭제한다. 동일한 최단 거리를 만드는 경우도 저장해서 삭제한다.
2. 그 다음 최단 거리 존재할 시 print, 없을 시 -1 print
-----------------*/

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define INF 0x7f7f7f7f
#define pi std::pair<int,int>
#define to first
#define c second
int n, m,  src, dst;
std::vector<int> p[500]; // 이전 경로
std::vector<pi> e[500]; // input

void remove_bridge(const int& d) { // 1.
	for (int i = 0; i < p[d].size(); i++)
	{
		int pre = p[d][i]; // 이전 경로
		for(int j=0;j<e[pre].size();j++)
			if (e[pre][j].to == d) // 출발지가 pre이고 목적지가 d인 곳 삭제
			{
				e[pre][j].c = INF;
				break;
			}
		remove_bridge(p[d][i]);
	}
	p[d].clear(); // 삭제가 끝났으므로 clear
}

int dij(bool flag) { // flag=true인 경우 삭제를 위해 이전 경로를 p vector에 할당한다.
	int cost[500];
	memset(cost, 0x7f, sizeof(cost));
	std::priority_queue<pi> Q;
	Q.push({ src,0 });
	cost[src] = 0;

	while (!Q.empty()) {
		pi now = Q.top(); // now.to = now.first = 현재 위치, now.c=now.second = 현재 까지의 비용
		Q.pop();
		for (int i = 0; i < e[now.to].size(); i++) {
			int n_dst = e[now.to][i].to,n_c= e[now.to][i].c; // e[now.to][i].to =n_dst =  도착지, n_c = e[now.to][i].c 비용
			if (n_c == INF || n_dst == src) continue;
			if (n_c + now.c < cost[n_dst])
			{
				cost[n_dst] = n_c + now.c;
				Q.push({ n_dst,cost[n_dst] });
				if (flag)
				{
					p[n_dst].clear(); // 갱신되었으므로 이것도 최신화
					p[n_dst].push_back(now.to); // 이전 경로 할당
				}
			}
			else if (flag&&n_c + now.c == cost[n_dst]) // 해당 지점까지 동일한 비용으로 가는 경우 추가
				p[n_dst].push_back(now.to); // 이전 경로 추가
		}
	}
	if (cost[dst] != INF)
		remove_bridge(dst);
	return cost[dst];
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	while (1) {
		std::cin >> n >> m;
		if (!n && !m)
			break;
		for (int i = 0; i < 500; i++) {
			e[i].clear();
			p[i].clear();
		}
		std::cin >> src >> dst;
		for (int i = 0; i < m; i++)
		{
			int s, d,p;
			std::cin >> s >> d>>p;
			e[s].push_back({ d,p });
		}
		int min = dij(true);
		if (min == INF)
			std::cout << -1 << '\n';
		else {
			int min2 = dij(false);
			if (min2 == INF) std::cout << -1 << '\n';
			else std::cout << min2 << '\n';
		}
	}
	return 0;
}