/*
Catch study 21/jan/4week
백준_13308 주유소
https://www.acmicpc.net/problem/13308

우선순위 큐 사용해서 해당 목적지에 처음 도착하는 값 return
해당 위치에 동일한 가격으로 방문한적 있는지 체크
*/
#include <iostream>
#include <queue>
#include <vector>
#define INF 2147000000000000000

struct Info {
	long long cost = 0;
	int price=0,pos=0;
	Info() {}
	Info(const long long& c, const int& pr, const int& p) { cost = c, price = pr, pos = p; }
	bool operator <(const Info& bb) const { return cost > bb.cost; }
};
struct Dst {
	int dst = 0, len = 0;
	Dst() {}
	Dst(const int& d, const int& l) { dst = d, len = l; }
};
#define vec2d std::vector<std::vector<Dst>>
#define vec2d_b std::vector<std::vector<bool>>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m; std::cin >> n >> m;
	std::vector<int> price(n); // 주유소 가격
	vec2d_b ck(n); // 방문 체크
	vec2d mp(n); // 거리 맵
	for (int i = 0; i < n; i++) {
		std::cin >> price[i];
		ck[i].resize(2501);
	}
	for (int i = 0; i < m; i++) {
		int src, dst, l; std::cin >> src >> dst >> l;
		mp[src - 1].push_back(Dst( dst - 1,l ));
		mp[dst - 1].push_back(Dst( src - 1,l ));
	}
	std::priority_queue<Info> Q;
	Q.push(Info(0, price[0], 0));
	while (!Q.empty()) {
		Info now = Q.top();
		Q.pop();
		if (now.pos == n - 1) { // 첫 번째로 목적지에 도착한 값 print 이후 종료
			std::cout << now.cost;
			return 0;
		}
		if (ck[now.pos][now.price]) continue; // 현재 위치에 해당 가격으로 가는 경우 체크
		ck[now.pos][now.price] = 1;
		for (int i = 0; i < mp[now.pos].size(); i++) {
			int d = mp[now.pos][i].dst, l = mp[now.pos][i].len, p = 0;
			if (now.price < price[d]) p = now.price; // 더 낮은 가격으로 갱신
			else p = price[d];
			Q.push(Info(now.cost + now.price*l, p, d)); // (계산된 비용, 갱신된 가격, 목적지 = 다음시작 위치)
		}
	}
}