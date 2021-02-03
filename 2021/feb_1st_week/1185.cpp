/*
Catch study 21/feb/1week
����_��������
https://www.acmicpc.net/problem/1185
*/
/*-----------------
Ǯ��
ũ�罺Į ���

1. n-1���� �游 ���ܾ� �ϹǷ� 
�ٽ� ����������� ���ư��� ���� ������ ���� �ǳʾߵȴ�.
���� ��߸���, ��������, (�� * 2)�� ������� ����ؾ��Ѵ�.
���������� ��߸����� ���� �ڽ�Ʈ�� ���� ������ ������ ���� ����� ���Ѵ�.

2. 
4-5-4-2-3-2-1-2-4
4�� 5, 4�� 2, 3�� 2, 1�� 2�� �̾��ִ� �κ��� ũ�罺Į�� ���ѱ�
�ش� ���� 2�� �̵���. 4�� ��� �����̱� ������ �ѹ� �� ����

5�� ���� +

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