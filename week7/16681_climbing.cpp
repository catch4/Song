/*
Catch study 7����
����_16681 ���
https://www.acmicpc.net/problem/16681
*/
/*
Ʋ�ȴ� ����
INF 2147000000���� 1000000000000�� �ٲٴϱ� ��....

���ͽ�Ʈ��� ǰ
val = ��ġ�� ���� vector
loss = �̵��� �Ÿ��� ���� vector
gain = ���̷� ���� �̵濡 ���� vector

1. ���� ������������ ����
2. �Ÿ� ������������ ����
3-1. �ö� �� ��ġ �ִ�ȭ �� �̵��� �Ÿ� ����
3-2. ������ �� ��ġ �ִ�ȭ, �̵��Ÿ� ����, ���̷� ����� �̵� ����
4. �б��� �������Ѱ�� Impossible, ������ ��� �ִ� ��ġ print
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
		if (idx == n - 1 || h[0].first>sort_h[i].first || val[idx] == -INF) continue; // ���� ���̺��� ���ų�, idx�� �б��̰ų�, �湮�� ���� ������ continue
		for (int j = 0; j < dist[idx].size(); j++)
		{
			if (h[idx].first >= h[dist[idx][j].p.dst].first) continue; // �������� ��������� ���� ���� ��� continue
			if (dist[idx][j].p.dst == n - 1) continue; // �������� �б��� ��� continue
			ll g = (ll)h[dist[idx][j].p.dst].first*e;
			ll l = ((ll)dist[idx][j].p.cost + loss[idx])*d;

			if (g - l > val[dist[idx][j].p.dst])
			{
				val[dist[idx][j].p.dst] = (ll)g - l; // 3-1.
				loss[dist[idx][j].p.dst] = (ll)dist[idx][j].p.cost + loss[idx];
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) { // ���� ū �������� Ž��
		if (h[n - 1].first > sort_h[i].first) break; // ������� �б����� ���� ���� ��� continue
		int idx = sort_h[i].second;
		if (idx == 0 || val[idx] == -INF)continue; // ������� �б��̰ų�, �湮�� ���� ���� ��� continue
		if (gain[idx] == -INF) gain[idx] = sort_h[i].first; // �湮�� ���� �ִµ�, ���̿� ���� �̵��� ���°��, ���� ���̷� �̵漳��
		for (int j = 0; j < dist[idx].size(); j++)
		{
			if (h[idx].first <= h[dist[idx][j].p.dst].first) continue; // ������� ���������� ���� ���� ��� continue
			if (dist[idx][j].p.dst == 0) continue; // �������� ���� ��� continue
			ll g = (ll)gain[idx] * e;
			ll l = ((ll)dist[idx][j].p.cost + loss[idx])*d;
			if (g - l > val[dist[idx][j].p.dst])
			{
				val[dist[idx][j].p.dst] = (ll)g - l; // 3-2.
				gain[dist[idx][j].p.dst] = gain[idx]; // �ֽ�ȭ �Ǿ����Ƿ� �������� ���� ���̿� ���� �̵� ����
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