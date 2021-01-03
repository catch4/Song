/*
Catch study 13����
����_5719 ���� �ִ� ���
https://www.acmicpc.net/problem/5719
*/
/*-----------------
Ʋ�ȴ� ����
clear ����� �����༭ �޸� �ʰ�

Ǯ��
1. ���� �ִ� �Ÿ��� �����Ѵ�. ������ �ִ� �Ÿ��� ����� ��쵵 �����ؼ� �����Ѵ�.
2. �� ���� �ִ� �Ÿ� ������ �� print, ���� �� -1 print
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
std::vector<int> p[500]; // ���� ���
std::vector<pi> e[500]; // input

void remove_bridge(const int& d) { // 1.
	for (int i = 0; i < p[d].size(); i++)
	{
		int pre = p[d][i]; // ���� ���
		for(int j=0;j<e[pre].size();j++)
			if (e[pre][j].to == d) // ������� pre�̰� �������� d�� �� ����
			{
				e[pre][j].c = INF;
				break;
			}
		remove_bridge(p[d][i]);
	}
	p[d].clear(); // ������ �������Ƿ� clear
}

int dij(bool flag) { // flag=true�� ��� ������ ���� ���� ��θ� p vector�� �Ҵ��Ѵ�.
	int cost[500];
	memset(cost, 0x7f, sizeof(cost));
	std::priority_queue<pi> Q;
	Q.push({ src,0 });
	cost[src] = 0;

	while (!Q.empty()) {
		pi now = Q.top(); // now.to = now.first = ���� ��ġ, now.c=now.second = ���� ������ ���
		Q.pop();
		for (int i = 0; i < e[now.to].size(); i++) {
			int n_dst = e[now.to][i].to,n_c= e[now.to][i].c; // e[now.to][i].to =n_dst =  ������, n_c = e[now.to][i].c ���
			if (n_c == INF || n_dst == src) continue;
			if (n_c + now.c < cost[n_dst])
			{
				cost[n_dst] = n_c + now.c;
				Q.push({ n_dst,cost[n_dst] });
				if (flag)
				{
					p[n_dst].clear(); // ���ŵǾ����Ƿ� �̰͵� �ֽ�ȭ
					p[n_dst].push_back(now.to); // ���� ��� �Ҵ�
				}
			}
			else if (flag&&n_c + now.c == cost[n_dst]) // �ش� �������� ������ ������� ���� ��� �߰�
				p[n_dst].push_back(now.to); // ���� ��� �߰�
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