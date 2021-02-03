/*
Catch study 21/feb/1week
백준_유럽여행
https://www.acmicpc.net/problem/1185
*/
/*-----------------
풀이
크루스칼 사용

1. n-1개의 길만 남겨야 하므로 
다시 출발지점으로 돌아가기 위해 동일한 길을 건너야된다.
따라서 출발마을, 도착마을, (길 * 2)의 비용으로 계산해야한다.
마지막으로 출발마을은 가장 코스트가 낮은 마을을 선택해 최종 결과에 더한다.

2. 
4-5-4-2-3-2-1-2-4
4와 5, 4와 2, 3과 2, 1과 2를 이어주는 부분이 크루스칼로 구한길
해당 길은 2번 이동함. 4는 출발 마을이기 때문에 한번 더 등장

5번 마을 +

-----------------*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Info {
	int s=0, e=0, c=0;
	bool operator<(const Info& bb)const {
		return c < bb.c;
	}
};

int getparent(std::vector<int>& parent, const int& now) {
	if (parent[now] == now) return now;
	return parent[now]=getparent(parent, parent[now]);
}

int main() {
	int n, p,cnt=0,idx=0,min_cost=2147000000,answer=0; std::cin >> n >> p;
	std::vector<int> cost(n),parent(n);
	std::vector<Info> road(p);
	for (int i = 0; i < n; i++) {
		std::cin >> cost[i];
		parent[i] = i;
		min_cost = std::min(min_cost, cost[i]);
	}
	for (int i = 0; i < p; i++) {
		std::cin >> road[i].s >> road[i].e >> road[i].c;
		road[i].s -= 1;
		road[i].e -= 1;
		road[i].c = road[i].c * 2 + cost[road[i].s] + cost[road[i].e];
	}
	sort(road.begin(), road.end());
	
	while (cnt < n - 1&&idx<p) {
		Info now = road[idx];
		idx+=1;
		int p1 = getparent(parent,now.s), p2 = getparent(parent,now.e);
		if (p1 != p2) {
			int min_val = std::min(p1, p2),max_val = std::max(p1, p2);
			parent[max_val] = min_val;
			answer += now.c;
		}
	}
	std::cout << answer + min_cost << '\n';
	return 0;
}