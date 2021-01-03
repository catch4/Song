/*
Catch study 7주차
백준_16681 등산
https://www.acmicpc.net/problem/16681
*/
/*
틀렸던 이유
INF 2147000000에서 1000000000000로 바꾸니깐 됨....

다익스트라로 품
val = 가치에 대한 vector
loss = 이동한 거리에 대한 vector
gain = 높이로 얻은 이득에 대한 vector

1. 높이 오름차순으로 정렬
2. 거리 오름차순으로 정렬
3-1. 올라갈 때 가치 최대화 및 이동한 거리 저장
3-2. 내려갈 때 가치 최대화, 이동거리 저장, 높이로 얻었던 이득 저장
4. 학교에 도착못한경우 Impossible, 도착한 경우 최대 가치 print
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000000
#define pi std::pair<int,int>
#define dst first
#define cost second
#define ll long long
int n, m, d, e, sh;
ll ret = 0;
std::vector<pi> h;

struct Path {
	pi p;
	Path() {}
	Path(const pi& t_p) { p = t_p; }
	bool operator<(const Path& bb)const {
		return p.cost < bb.p.cost;
	}
};
#define vec_P std::vector<std::vector<Path>>
bool dijkstra(vec_P& dist, std::vector<pi>& sort_h) {
	std::vector<ll> val(n, -INF), loss(n, INF), gain(n, -INF);
	val[0] = 0, loss[0] = 0;
	for (int i = 0; i < n; i++) {
		int idx = sort_h[i].second;
		if (idx == n - 1 || h[0].first>sort_h[i].first || val[idx] == -INF) continue; // 집의 높이보다 낮거나, idx가 학교이거나, 방문된 적이 없으면 continue
		for (int j = 0; j < dist[idx].size(); j++)
		{
			if (h[idx].first >= h[dist[idx][j].p.dst].first) continue; // 목적지가 출발지보다 높지 않을 경우 continue
			if (dist[idx][j].p.dst == n - 1) continue; // 목적지가 학교일 경우 continue
			ll g = (ll)h[dist[idx][j].p.dst].first*e;
			ll l = ((ll)dist[idx][j].p.cost + loss[idx])*d;

			if (g - l > val[dist[idx][j].p.dst])
			{
				val[dist[idx][j].p.dst] = (ll)g - l; // 3-1.
				loss[dist[idx][j].p.dst] = (ll)dist[idx][j].p.cost + loss[idx];
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) { // 높이 큰 순서부터 탐색
		if (h[n - 1].first > sort_h[i].first) break; // 출발지가 학교보다 높이 낮은 경우 continue
		int idx = sort_h[i].second;
		if (idx == 0 || val[idx] == -INF)continue; // 출발지가 학교이거나, 방문된 적이 없는 경우 continue
		if (gain[idx] == -INF) gain[idx] = sort_h[i].first; // 방문된 적이 있는데, 높이에 대한 이득이 없는경우, 현재 높이로 이득설정
		for (int j = 0; j < dist[idx].size(); j++)
		{
			if (h[idx].first <= h[dist[idx][j].p.dst].first) continue; // 출발지가 목적지보다 높지 않은 경우 continue
			if (dist[idx][j].p.dst == 0) continue; // 목적지가 집인 경우 continue
			ll g = (ll)gain[idx] * e;
			ll l = ((ll)dist[idx][j].p.cost + loss[idx])*d;
			if (g - l > val[dist[idx][j].p.dst])
			{
				val[dist[idx][j].p.dst] = (ll)g - l; // 3-2.
				gain[dist[idx][j].p.dst] = gain[idx]; // 최신화 되었으므로 경유지에 현재 높이에 대한 이득 유지
				loss[dist[idx][j].p.dst] = (ll)dist[idx][j].p.cost + loss[idx];
			}
		}
	}
	ret = val[n - 1];
	if (ret == -INF) return false; // 4.
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> m >> d >> e;
	h.resize(n);
	vec_P dist(n);
	for (int i = 0; i < n; i++) {
		std::cin >> h[i].first;
		h[i].second = i;
	}
	std::vector<pi> sort_h = h;
	sort(sort_h.begin(), sort_h.end()); // 1.
	for (int i = 0; i < m; i++)
	{
		int idx1, idx2, di; std::cin >> idx1 >> idx2 >> di;
		dist[idx1 - 1].push_back(Path({ idx2 - 1,di }));
		dist[idx2 - 1].push_back(Path({ idx1 - 1,di }));
	}
	for (int i = 0; i < n; i++) sort(dist[i].begin(), dist[i].end()); // 2.
	if (dijkstra(dist, sort_h)) std::cout << ret << '\n'; // 4.
	else std::cout << "Impossible\n";
}