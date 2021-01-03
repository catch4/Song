/*
Catch study 3주차
백준_1516 게임개발
https://www.acmicpc.net/problem/1516
*/
/*
dfs,dy로 접근함.
결과 = 선행 건물 중 제일 오래 걸리는 건물 + 현재 건물 걸리는 시간
0. 걸리는 시간 및 선행 건물 입력
1. 결과 시간이 0으로 되어 있는 경우 dfs
2-1. 선행 건물 중 ret_time이 가장 큰 값.
2-2. ret_time이 0인 경우 dfs
2-3. 선행 건물 중 ret_time이 가장 큰 값과 현재 시간을 더해 저장 및 return
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

