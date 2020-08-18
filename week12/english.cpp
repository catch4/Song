/*
Catch study 12주차
프로그래머스_영어 끝말잇기
https://programmers.co.kr/learn/courses/30/lessons/12981
*/
/*-----------------
풀이
해쉬 이용해서 체크
-----------------*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	answer.push_back(0);
	answer.push_back(0);
	bool flag = false;
	int i = 1,cur=1,turn=1;
	string tmp = words[0];
	unordered_map<string, bool> mp;
	mp[tmp] = 1;
	while (!flag && i<words.size())
	{
		std::cout << words[i] << '\n';
		if (mp[words[i]] || tmp[tmp.size() - 1] != words[i][0])
		{
			answer[0] = cur+1, answer[1] = turn;
			flag = true;
		}
		else {
			mp[words[i]] = 1;
			tmp = words[i];
		}
		i++;
		cur++;
		if (cur==n)
		{
			cur = 0;
			turn += 1;
		}
	}
	return answer;
}

int main() {
	int n = 3;
	vector<string> words;
	words.push_back("tank");
	words.push_back("kick");
	words.push_back("know");
	words.push_back("wheel");
	words.push_back("land");
	words.push_back("dream");
	words.push_back("mother");
	words.push_back("robot");
	words.push_back("tank");
	std::vector<int> answer = solution(n,words);
	std::cout << answer[0] << " " << answer[1] << '\n';
}