/*
Catch study 3����
����_1516 ���Ӱ���
https://www.acmicpc.net/problem/1516
*/
/*
dfs,dy�� ������.
��� = ���� �ǹ� �� ���� ���� �ɸ��� �ǹ� + ���� �ǹ� �ɸ��� �ð�
0. �ɸ��� �ð� �� ���� �ǹ� �Է�
1. ��� �ð��� 0���� �Ǿ� �ִ� ��� dfs
2-1. ���� �ǹ� �� ret_time�� ���� ū ��.
2-2. ret_time�� 0�� ��� dfs
2-3. ���� �ǹ� �� ret_time�� ���� ū ���� ���� �ð��� ���� ���� �� return
*/
#include <iostream>
#include <vector>
#include <algorithm>
struct Build {
	int time;
	std::vector<int> pre;
	int ret_time = 0;
};

int dfs(std::vector<Build>& builds, const int& now) {
	int max = 0;
	// 2-1.
	for (int i = 0; i < builds[now].pre.size(); i++)
		if (!builds[builds[now].pre[i]].ret_time) // 2-2.
			max = std::max(max, dfs(builds, builds[now].pre[i]));
		else
			max = std::max(max, builds[builds[now].pre[i]].ret_time);
	// 2-1.

	// 2-3.
	builds[now].ret_time = builds[now].time + max;
	return builds[now].ret_time;
	// 2-3.
}

int main() {
	int n; std::cin >> n;
	std::vector<Build> builds(n);
	// 0.
	for (int i = 0; i < n; i++)
	{
		std::cin >> builds[i].time;
		int condition;
		std::cin >> condition;
		while (condition!=-1) {
			builds[i].pre.push_back(condition-1);
			std::cin >> condition;
		}
	}
	// 0.

	
	for (int i = 0; i < n; i++)
	{
		if (builds[i].ret_time)
			std::cout << builds[i].ret_time << '\n';// 1.
		else
			std::cout<<dfs(builds, i)<<'\n';		
	}
	return 0;
}

