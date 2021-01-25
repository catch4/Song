/*
Catch study 21/jan/4week
����_13308 ������
https://www.acmicpc.net/problem/13308

�켱���� ť ����ؼ� �ش� �������� ó�� �����ϴ� �� return
�ش� ��ġ�� ������ �������� �湮���� �ִ��� üũ
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
	std::vector<int> price(n); // ������ ����
	vec2d_b ck(n); // �湮 üũ
	vec2d mp(n); // �Ÿ� ��
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
		if (now.pos == n - 1) { // ù ��°�� �������� ������ �� print ���� ����
			std::cout << now.cost;
			return 0;
		}
		if (ck[now.pos][now.price]) continue; // ���� ��ġ�� �ش� �������� ���� ��� üũ
		ck[now.pos][now.price] = 1;
		for (int i = 0; i < mp[now.pos].size(); i++) {
			int d = mp[now.pos][i].dst, l = mp[now.pos][i].len, p = 0;
			if (now.price < price[d]) p = now.price; // �� ���� �������� ����
			else p = price[d];
			Q.push(Info(now.cost + now.price*l, p, d)); // (���� ���, ���ŵ� ����, ������ = �������� ��ġ)
		}
	}
}