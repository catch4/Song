/*
Catch study 13주차
백준_7579
https://www.acmicpc.net/problem/7579
*/
/*-----------------
풀이
코스트로 확보가능한 메모리 dp
-----------------*/
#include <iostream>
#include <vector>
#include <algorithm>
int n, m, t_cost =0;
std::vector<int> mem, c, dp;

int main() {
	std::cin >> n >> m;
	mem.resize(n); c.resize(n);
	for (int i = 0; i < n; i++) std::cin >> mem[i];
	for (int i = 0; i < n; i++) {
		std::cin >> c[i];
		t_cost += c[i];
	}
	dp.resize(t_cost + 1);
	for (int i = 0; i < n; i++)
		for (int j = t_cost; j >= c[i]; j--)
			dp[j] = std::max(dp[j], dp[j - c[i]] + mem[i]);

	for(int i=0;i<=t_cost;i++)
		if (dp[i] >= m) {
			std::cout << i << '\n';
			break;
		}
	return 0;
}