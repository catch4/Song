/*
Catch study 8주차
백준_2252 line
https://www.acmicpc.net/problem/2252
*/
/*-----------------------------
풀이
dfs와 dp?로 풀었다.
자신보다 큰 숫자가 모두 출력되면 출력될 수 있다.

1. b 인덱스에 a(b보다 큰 숫자) 추가
2. 아직 출력이 안된 경우 자신보다 큰 숫자 출력하고 출력
------------------------------*/

#include <iostream>
#include <vector>
#define vec_2d std::vector<std::vector<int>>
void dfs(vec_2d& vec,const int& idx,std::vector<bool>& ck) { // 2.
	for (int i = 0; i < vec[idx].size(); i++) {
		if (ck[vec[idx][i]]) continue;
		dfs(vec, vec[idx][i], ck);
		std::cout << vec[idx][i]+1<<" ";
		ck[vec[idx][i]] = 1;
	}
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m; std::cin >> n >> m;
	vec_2d vec(n);
	std::vector<bool> ck(n);
	for (int i = 0; i < m; i++) {
		int a, b; std::cin >> a >> b;
		vec[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++)
		if (!ck[i]) {
			dfs(vec, i, ck); // 2.
			ck[i] = 1;
			std::cout << i + 1 << " ";
		}
	return 0;
}