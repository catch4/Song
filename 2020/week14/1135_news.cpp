/*
Catch study 14����
����_���� ���ϱ�
https://www.acmicpc.net/problem/1135
*/
/*-----------------
Ǯ��
dp
1. �� ��� ���� �ڽ� ��� ��ȣ ����
2. �ڽ� ����� �ڽ�Ʈ�� ���� ������ +1, ���� ������ +2,.... �߿� ���� ū �� ���� ����� ���
-----------------*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
	std::vector<int> c; // 1.
	int cost = -1;
};

std::vector<Node> nodes;

bool cmp(const int& a, const int&b) {
	return nodes[a].cost>nodes[b].cost;
}

void dfs(const int& now) {
	if (!nodes[now].c.size()) nodes[now].cost = 0;
	else {
		std::vector<int>& p = nodes[now].c;
		for (int i = 0; i<p.size(); i++) // �켱 �ڽ�Ʈ ����
			if (nodes[p[i]].cost == -1)
				dfs(p[i]);

		sort(p.begin(), p.end(), cmp); // �ڽ�Ʈ �� �������� ����

		for (int i = 0; i<p.size(); i++) // 2. 
			nodes[now].cost = std::max(nodes[now].cost, nodes[p[i]].cost + i + 1);

	}
}

int main() {
	int n, max = 0; std::cin >> n;
	nodes.resize(n);
	for (int i = 0; i<n; i++)
	{
		int num; std::cin >> num;
		if (num == -1) continue;
		else nodes[num].c.push_back(i); // 1.
	}
	dfs(0);
	std::cout << nodes[0].cost << '\n';
	return 0;
}