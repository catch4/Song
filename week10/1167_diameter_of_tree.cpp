/*
Catch study 10주차
백준_트리의 지름
https://www.acmicpc.net/problem/1167
*/
/*-----------------
풀이
옛날에 풀었음

한 지점 v0에서 가장 먼거리 v1을 찾은 이후
v1에서 가장 먼 지점 까지의 거리가 트리의 지름
v0는 첫번째 index로 하였다.

v0에서 v1을 찾았는데 안되는 경우
1 4 9 2 3 -1
2 3 5 1 3-1
3 2 5 -1
4 1 9 -1
이 경우 3-2-1-4로 연결되어 있고 v1=4, 거리는 9
그런데 트리의 지름은 3에서 4까지의 거리인 17
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

