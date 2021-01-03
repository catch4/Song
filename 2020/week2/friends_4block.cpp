/*
Catch study 2주차
프로그래머스 프렌즈4블록
https://programmers.co.kr/learn/courses/30/lessons/17679
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;
int n, m;
int dx[3] = { 1,0,1 };
int dy[3] = { 0,1,1 };
int answer = 0;


void pang(std::vector<string>& map, std::vector<std::vector<bool>>& ck)
{
	// 체크된 배열 0
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ck[i][j]) {
				answer++;
				map[i][j] = 0;
			}
		}
	}

	// 빈 공간 down
	for (int j = 0; j < m; j++)
	{
		int target = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (target&&map[i][j]) {
				map[target][j] = map[i][j];
				map[i][j] = 0;
				target -= 1;
			}
			else if (!target && !map[i][j]) target = i;
		}
	}
}

bool block_search(std::vector<string>& map, std::vector<std::vector<bool>>& ck, std::vector<std::vector<bool>>& visit, const int& i, const int& j)
{
	// 방문 체크
	visit[i][j] = 1;
	int cnt = 0;
	for (int z = 0; z < 3; z++)
	{
		int n_x = j + dx[z];
		int n_y = i + dy[z];
		if (n_x >= 0 && n_x < m&&n_y >= 0 && n_y < n)
			if (map[i][j] == map[n_y][n_x]) cnt++;
	}
	// 3개 카운트시 터지는 걸로 체크
	if (cnt == 3)
	{
		ck[i][j] = 1;
		for (int z = 0; z < 3; z++)
		{
			int n_x = j + dx[z];
			int n_y = i + dy[z];
			ck[n_y][n_x] = 1;
			if (!visit[n_y][n_x])	block_search(map, ck, visit, n_y, n_x);
		}
		return true;
	}
	return false;
}

int solution(int c_n, int c_m, vector<string> map) {
	n = c_n;
	m = c_m;
	bool flag = true;
	while (flag) {
		flag = false;
		std::vector<std::vector<bool>> ck(n, std::vector<bool>(m, 0));
		std::vector<std::vector<bool>> visit(n, std::vector<bool>(m, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!visit[i][j] && map[i][j]) {
					// 한번이라도 터지는게 발생시 flag는 true
					if (block_search(map, ck, visit, i, j)) flag = true;
				}
		if (flag) pang(map, ck);
	}
	return answer;
}
