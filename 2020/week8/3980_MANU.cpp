/*
Catch study 8주차
백준_3980 선발 명단
https://www.acmicpc.net/problem/3980
*/
/*-----------------------------
땅따먹기 처럼 풀어야 하나 고민하다가
브루트 포스로 품
------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#define vec_2d std::vector<std::vector<int>>
int answer;

void dfs(vec_2d& player,std::vector<bool>& ck,const int& sum,
	const int& picked) {
	if (picked == 11) {
		answer = std::max(answer, sum);
		return;
	}
	else {
		for(int i=0;i<11;i++)
			if (!ck[i]&&player[picked][i]) {
				ck[i] = 1;
				dfs(player, ck, sum + player[picked][i], picked+1);
				ck[i] = 0;
			}
	}
}

int main() {
	int c; std::cin >> c;
	while (c--) {
		answer = 0;
		std::vector<std::vector<int>> player(11,std::vector<int> (11,0));
		std::vector<bool> ck(11);
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				std::cin >> player[i][j];
		dfs(player, ck, 0, 0);
		std::cout << answer << '\n';
	}
}