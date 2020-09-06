/*
Catch study 14주차
백준_뉴스 전하기
https://www.acmicpc.net/problem/1135
*/
/*-----------------
풀이
dp
1. 각 노드 마다 자식 노드 번호 저장
2. 자식 노드중 코스트가 제일 작은거 +1, 다음 작은거 +2,.... 중에 제일 큰 게 현재 노드의 비용
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
		for (int i = 0; i<p.size(); i++) // 우선 코스트 구함
			if (nodes[p[i]].cost == -1)
				dfs(p[i]);

		sort(p.begin(), p.end(), cmp); // 코스트 값 기준으로 정렬

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