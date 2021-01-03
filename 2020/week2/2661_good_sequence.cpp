/*
Catch study 2주차
백준_2661 좋은 수열
https://www.acmicpc.net/problem/2661
*/

/*
풀이
결과하나만 나오면 되고 최대 n도 80이라 dfs로 구현
1~3 순서대로 dfs를 탐색하고 결과가 나오면 무조건 
최소값이기 때문에 따로 처리 X

0. 인접 배열 비교, 최대 크기는 현재 만들어진 배열/2의 몫
1. 좋은 수열이 완성될때만 다음 크기의 배열 탐색
2. 결과가 나왔으면 탐색 탈출
*/

#include <iostream>
#include <vector>
#include <string>
int n;
bool flag = 0;

bool good(std::string str) {
	int len = str.size() / 2;
	// 0.
	for (int i = 1; i <= len; i++)
	{
		int start1 = str.size() - i;
		int start2 = start1 - i;
		std::string str1 = "";
		std::string str2 = "";
		for (int j = start1;j< str.size(); j++)
			str1 += str[j];
		for (int j = start2; j < start1; j++)
			str2 += str[j];
		if (str1 == str2)
			return false;
	}
	// 0.
	return true;
}

void dfs(std::string str)
{
	if (str.size() == n) {
		std::cout << str;
		flag = 1; // 2.
	}
	else {
		for (int i = 1; i <= 3; i++)
		{
			// 1.
			if (good(str + char(i + '0')))
				dfs(str + char(i + '0'));
			// 1.
			if (flag) return; // 2.
		}
	}
}

int main() {
	std::cin >> n;
	dfs("");
	return 0;
}