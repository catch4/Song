/*
Catch study 13주차
백준_17825 주사위 윷놀이
https://www.acmicpc.net/problem/17825
*/
/*-----------------
틀렸던 이유
- 25 중복 체크 안함
- 40 중복 체크 안함
- 배열을 아래처럼 만들어놔서 25,30,35,40 싹다 중복 체크해야 하는데 안함

풀이
- 중복을 체크에 신경쓰고 나머지는 브루트 포스로 구현한다.
-----------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#define pi std::pair<int,int>
int dice[10],answer;
std::vector<int> map[5];

void dfs(std::vector<pi> pos, const int& used, const int& sum);
void init() { // 말판 초기화
	map[0].resize(21);
	map[1].resize(8);
	map[2].resize(7);
	map[3].resize(8);
	for (int i = 1; i < 21; i++)
		map[0][i] = i * 2;
	map[1] = { 10,13,16,19,25,30,35,40 };
	map[2] = { 20,22,24,25,30,35,40 };
	map[3] = { 30,28,27,26,25,30,35,40 };
}

void move(std::vector<pi> pos, const int& k, const int& used, const int& sum, const int& num) {
	int i = pos[k].first, j = pos[k].second;
	if (j + num >= map[i].size()) { // 도착하는 경우
		pos[k].first = -1;
		dfs(pos, used + 1, sum);
	}
	else if (!i&&map[i][j + num] < 40 && map[i][j + num] % 10 == 0) { // 맨처음 배열에서 다른 배열로 넘어가야 하는 경우
		for (int z = 0; z < 4; z++)
			if (pos[z].first == map[i][j + num] / 10 && !pos[z].second) return;
		pos[k].first = map[i][j + num] / 10;
		pos[k].second = 0;
		dfs(pos, used + 1, sum + map[i][j + num]);
	}
	else { // 나머지 경우
		for (int z = 0; z < 4; z++) { 
			if (pos[z].first == i && pos[z].second == j + num) return; // 완전 배열 겹치는 경우
			else if (j + num == map[i].size() - 1 && pos[z].second == map[pos[z].first].size() - 1) return; // 40 겹치는 경우
			else if (i>=1&&pos[z].first>=1 && j+num>=3&&pos[z].second>=3&& map[i][j + num]==map[pos[z].first][pos[z].second]) return; // 1,2,3 번째 배열은 25부터 싹다 중복체크
		}
		pos[k].first = i;
		pos[k].second = j + num;
		dfs(pos, used + 1, sum + map[i][j + num]);
	}
}

void dfs(std::vector<pi> pos,const int& used, const int& sum) {
	answer = std::max(answer, sum);
	if (used == 10) // 주사위 10개 다씀
		return;
	else {
		for(int k=0;k<4;k++)
			if(pos[k].first!=-1) // first가 -1인 말은 이미 도착한 말
				move(pos, k, used, sum, dice[used]);
	}
}

int main() {
	std::vector<pi> pos(4, { 0,0 });
	for (int i = 0; i < 10; i++) std::cin >> dice[i];
	init();
	dfs(pos, 0, 0);
	std::cout << answer << '\n';
	return 0;
}