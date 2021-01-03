/*
Catch study 2����
����_1916 �ּҺ��
https://www.acmicpc.net/problem/1916
*/

/*
Ǯ��

Ʋ������
�� ó�� �ܼ� dfs�� Ǯ���� �� �ð��ʰ�
-> ���ͽ�Ʈ�� �˰��� ���

0. ������ INF ������ �ʱ�ȭ
1. ���ͽ�Ʈ��
	1-1. start ������ �ش��ϴ� ����� 0���� �ʱ�ȭ
	1-2. ���� start �������� nxt�� ���� ��뺸�� 
		 start �������� cur������ ���� ��� + cur�������� nxt�� ���� �����
		 �� ������ ��� �ش� ������� ���� �� �켱���� ť�� push.
	1-3. ����� INF�� ��� �����÷ο찡 �� �� �����Ƿ� ó������ �ʰ� pop��
	1-4. ť�� �� ������ �ݺ�
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