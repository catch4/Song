/*
Catch study 11주차
백준_거짓말
https://www.acmicpc.net/problem/1043
*/
/*-----------------
풀이
다리 문제로 생각하고 진실을 아는 지점에서
갈 수 없는 지점의 개수 카운팅

1. 진실 아는 사람 저장
2. 사람당 간 파티 체크
3. 
-----------------*/

#include <iostream>
#include <vector>
int n, m,p_n,answer;
bool member[50][50]; // 2.
bool peo_ck[50],par_ck[50]; // 3. 사람, 파티 visited
std::vector<int> police; // 1. 진실 아는 사람

void dfs(const int& people) {
	for (int i = 0; i < m; i++)
	{
		if (par_ck[i]||!member[people][i]) continue;
		for (int p = 0; p < n; p++) {
			if (peo_ck[p]) continue;
			if (member[p][i])
			{
				peo_ck[p] = 1; // 체크 안한 사람, 파티면 체크
				dfs(p);
			}
		}
		par_ck[i] = 1;
	}
}

int main() {
	std::cin >> n >> m>>p_n;
	police.resize(p_n);
	answer = m; // 초기값 = m
	for (int i = 0; i < p_n; i++) std::cin >> police[i]; // 1.
	for (int j = 0; j < m; j++) {
		int tmp; std::cin >> tmp;
		for (int i = 0; i < tmp; i++) {
			int tmp2; std::cin >> tmp2;
			member[tmp2 - 1][j] = 1;
		}
	}
	if (!p_n) std::cout << m;
	else {
		for (int i = 0; i < p_n; i++) {
			peo_ck[police[i]-1] = 1;
			dfs(police[i]-1);
		}
		for (int i = 0; i < m; i++)
			if (par_ck[i]) answer--; // 거짓말 못하는 파티 차감
		std::cout << answer;
	}
	
}