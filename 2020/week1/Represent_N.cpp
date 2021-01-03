/*
Catch study 1주차
프로그래머스_N으로 표현
https://programmers.co.kr/learn/courses/30/lessons/42895
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void search(vector<vector<int>>& values, map<int, int>& mp,
	const int&N,const int& idx1,const int& idx2,const int& idx)
{
	for (int i = 0; i < values[idx1].size(); i++)
	{
		for (int j = 0; j < values[idx2].size(); j++)
		{
			int comb[4]; // 사칙연산 담을 배열
			comb[0] = values[idx1][i] + values[idx2][j];
			// 음수 필요 없음
			comb[1] = abs(values[idx1][i] - values[idx2][j]);
			// 0되는 값 필요 없음 = 분모가 더 작아야함
			comb[2] = values[idx1][i] > values[idx2][j] ? values[idx1][i] / values[idx2][j] : values[idx2][j] / values[idx1][i];
			comb[3] = values[idx1][i] * values[idx2][j];
			for (int z = 0; z < 4; z++)
			{
				if (comb[z] > 0 && !mp[comb[z]])
				{
					values[idx].push_back(comb[z]);
					mp[comb[z]] = idx;
				}
			}
		}
	}
}

int solution(int N, int number) {
	map<int, int> mp;
	vector<vector<int>> values(8); // 각 idx=N사용 횟수로 만들 수 있는 값
	mp[N] = 1;
	int con = N; // NN형태 만들 배열
	values[0].push_back(N);
	for (int i = 1; i < 8; i++)
	{
		for (int j = 0; j < i+1/2; j++)
			search(values, mp, N, j,i-j-1,i);
		con =con*10 +N;
		mp[con] = i;
		values[i].push_back(con);
		if (mp[number]) return i + 1; // 찾은 경우 바로 return
	}
	return -1; // 8개로 만들 수 없으므로 -1값 return
}
