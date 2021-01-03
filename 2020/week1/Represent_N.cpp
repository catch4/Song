/*
Catch study 1����
���α׷��ӽ�_N���� ǥ��
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
			int comb[4]; // ��Ģ���� ���� �迭
			comb[0] = values[idx1][i] + values[idx2][j];
			// ���� �ʿ� ����
			comb[1] = abs(values[idx1][i] - values[idx2][j]);
			// 0�Ǵ� �� �ʿ� ���� = �и� �� �۾ƾ���
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
	vector<vector<int>> values(8); // �� idx=N��� Ƚ���� ���� �� �ִ� ��
	mp[N] = 1;
	int con = N; // NN���� ���� �迭
	values[0].push_back(N);
	for (int i = 1; i < 8; i++)
	{
		for (int j = 0; j < i+1/2; j++)
			search(values, mp, N, j,i-j-1,i);
		con =con*10 +N;
		mp[con] = i;
		values[i].push_back(con);
		if (mp[number]) return i + 1; // ã�� ��� �ٷ� return
	}
	return -1; // 8���� ���� �� �����Ƿ� -1�� return
}
