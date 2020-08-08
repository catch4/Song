/*
Catch study 10����
����_Ʈ���� ����
https://www.acmicpc.net/problem/1167
*/
/*-----------------
Ǯ��
������ Ǯ����

�� ���� v0���� ���� �հŸ� v1�� ã�� ����
v1���� ���� �� ���� ������ �Ÿ��� Ʈ���� ����
v0�� ù��° index�� �Ͽ���.

v0���� v1�� ã�Ҵµ� �ȵǴ� ���
1 4 9 2 3 -1
2 3 5 1 3-1
3 2 5 -1
4 1 9 -1
�� ��� 3-2-1-4�� ����Ǿ� �ְ� v1=4, �Ÿ��� 9
�׷��� Ʈ���� ������ 3���� 4������ �Ÿ��� 17
-----------------*/


#include <iostream>
#include <vector>
int max = 0;
int far;
void DFS(std::vector<std::vector<std::pair<int, int> >>& vec,
	std::vector<int>& ck,
	const int &now,const int& cost)
{
	ck[now] = 1;
	if (cost > max) {
		far = now;
		max = cost;
	}

	for (int j = 0; j < vec[now].size(); j++)
		if (!ck[vec[now][j].first])
			DFS(vec, ck, vec[now][j].first, cost + vec[now][j].second);
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,n1,n2,cost;
	std::cin >> n;
	std::vector<std::vector<std::pair<int, int> >> vec(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> n1;
		while (1)
		{
			std::cin >> n2;
			if (n2 == -1) break;
			std::cin >> cost;
			vec[n1 - 1].push_back({ n2 - 1,cost });
			vec[n2 - 1].push_back({ n1 - 1,cost });
		}
	}
	std::vector<int> ck(n);
	DFS(vec, ck, 0, 0);
	for (int i = 0; i < n; i++)
		ck[i] = 0;
	DFS(vec, ck, far, 0);
	std::cout << max << std::endl;
	return 0;
}

