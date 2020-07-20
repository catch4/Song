/*
Catch study 8주차
백준_3980 선발 명단
https://www.acmicpc.net/problem/3980
*/
/*-----------------------------
틀렸던이유
"불가능할 시 -1을 출력한다" 빼먹음

풀이
플로이드 와샬로 품

1. 각각 비용 최신화
2. 출발지로 돌아온 경우 answer 최신화
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