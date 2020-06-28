/*
Catch study 4주차
프로그래머스_단체사진 찍기
https://programmers.co.kr/learn/courses/30/lessons/1835
*/
/*
브루트 포스로 품
1. dfs로 모든 경우의 수 찾기
2-1. 8개의 조합이 갖춰지면 모든 data에 대해
   조건 확인
2-2. index 반환하고 index끼리의 차이 이용해서 비교
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
char ch[8] = { 'A','C','F','J','M','N','R','T' };

int idx_search(char& ch, std::vector<char>& friends) // 2-2.
{
	for (int i = 0; i < friends.size(); i++)
		if (friends[i] == ch) return i;
}

bool check(char& oper, int& num, const int& dst_num)
{
	if (oper == '=') {
		if (num == dst_num) return true;
		else return false;
	}
	else if (oper == '<') {
		if (num < dst_num) return true;
		else return false;
	}
	else {
		if (num > dst_num) return true;
		else return false;
	}
}

// 2-1.
bool condition_check(vector<string>& data, vector<char>& friends)
{
	for (int i = 0; i < data.size(); i++)
	{
		int num = abs(idx_search(data[i][0], friends) - idx_search(data[i][2], friends))-1; // 2-2.
		if(!check(data[i][3], num, data[i][4] - '0')) return false;
	}
	return true;
}

// 1.
void dfs(vector<string>& data,vector<char>& friends, vector<bool>& ck,const int& choiced,int& answer) {
	if (choiced == 8)
	{
		if (condition_check(data, friends)) answer+=1; // 2-1.
	}
	else {
		for (int i = 0; i < 8; i++)
		{
			if (!ck[i])
			{
				ck[i] = 1;
				friends[choiced] = ch[i];
				dfs(data, friends, ck, choiced + 1, answer);
				ck[i] = 0;
			}
		}
	}
}

int solution(int n, vector<string> data) {
	int answer = 0;
	std::vector<char> friends(8);
	std::vector<bool> ck(8);
	dfs(data, friends, ck, 0, answer);
	return answer;
}

int main() {
	int n; std::cin >> n;
	vector<string> data(n);
	for (int i = 0; i < n; i++)
		std::cin >> data[i];
	std::cout << solution(n, data) << std::endl;
}
