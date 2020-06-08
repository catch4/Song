///*
//프로그래머스 프렌즈4블록
//https://programmers.co.kr/learn/courses/30/lessons/17679
//*/

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
	// 체크된 부분 0으로 채우고 카운트
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			if (ck[i][j]) {
				answer++;
				map[i][j] = 0;
			}
		}
	}

	for (int j = 0; j < m; j++)
	{
		bool flag = true;
		while (flag) {
			flag = false;
			for (int i = n - 2; i >= 0; i--)
			{
				if (map[i][j] != 0 && map[i + 1][j] == 0)
				{
					map[i + 1][j] = map[i][j];
					map[i][j] = 0;
					flag = true;
				}
			}
		}
	}

}

// 인접 2x2 찾는 부분
bool block_search(std::vector<string>& map, std::vector<std::vector<bool>>& ck, const int& i, const int& j)
{
	int cnt = 0;
	for (int z = 0; z < 3; z++)
	{
		int n_x = j + dx[z];
		int n_y = i + dy[z];
		if (n_x >= 0 && n_x < m&&n_y >= 0 && n_y < n)
			if (map[i][j] == map[n_y][n_x]) cnt++;
	}
	if (cnt == 3)
	{
		ck[i][j] = 1;
		for (int z = 0; z < 3; z++)
		{
			int n_x = j + dx[z];
			int n_y = i + dy[z];

			ck[n_y][n_x] = 1;
			block_search(map, ck, n_y, n_x);
		}

		return true;
	}
	return false;
}

// n이랑 m이랑 문제랑 바뀜
int solution(int c_n, int c_m, vector<string> map) { 
	n = c_n;
	m = c_m;
	bool flag = true;
	while (flag) {
		flag = false;
		std::vector<std::vector<bool>> ck(n, std::vector<bool>(m, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!ck[i][j] && map[i][j]) {
					if (block_search(map, ck, i, j)) flag = true;
				}
		if (flag) pang(map, ck);
	}
	return answer;
}

