/*
Catch study 9주차
백준_Dance Dance Revolution
https://www.acmicpc.net/problem/2342
*/
/*-----------------
풀이
l과 r로 입력되었을 때의 최소값 저장
-----------------*/
#include<iostream>
#include<vector>
#include <algorithm>
#define pi std::pair<int,int>
std::vector<int> pump[5][5];
std::vector<int> input;
int n;
int step(const int&src, const int&dst)
{
	if (src == 0) return 2;
	if (src == dst) return 1;
	if (abs(src - dst) == 2) return 4;
	else return 3;
}

int dfs(const int& i,const int& l,const int& r) {
	int num;
	if (i == n - 1)
		num=std::min(step(l,input[i]) ,step(input[i],r));
	else if (l==input[i] || r==input[i])
	{
		if (pump[l][r][i + 1])
			num = 1 + pump[l][r][i + 1];
		else
			num = 1 + dfs( i + 1, l, r);
	}
	else {
		int l_min=step(l,input[i]), r_min=step(r,input[i]);
		if (pump[input[i]][r][i + 1])
			l_min += pump[input[i]][r][i + 1];
		else
			l_min +=dfs( i + 1, input[i], r);
		
		if (pump[l][input[i]][i + 1])
			r_min += pump[l][input[i]][i + 1];
		else
			r_min += dfs(i + 1, l, input[i]);
		
		num = std::min(l_min, r_min);
	}
	return pump[l][r][i] = num;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int num;
	while (std::cin >> num&&num){
		input.push_back(num);
	}
	n = input.size();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			pump[i][j].resize(n, 0);
		}
	}
	int answer = 2 + dfs(1, input[0], 0);
	std::cout << answer << '\n';
	return 0;
}