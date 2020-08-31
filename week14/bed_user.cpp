/*
week14 
프로그래머스 불량 사용자
https://programmers.co.kr/learn/courses/30/lessons/64064
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n, answer;
std::unordered_map<string, bool> mp;
bool check(string& ban, string& user_id)
{
	if (ban.size() != user_id.size()) return false;
	for (int i = 0; i < ban.size(); i++)
	{
		if (ban[i] == '*') continue;
		else if (ban[i] != user_id[i]) return false;
	}
	return true;
}

void dfs(std::vector<std::vector<int>>& cand, const int& now, std::vector<bool>& ck, string maked) {
	if (now == n) {
		sort(maked.begin(), maked.end());
		if (mp[maked]) return;
		else {
			mp[maked] = 1;
			answer++;
		}
	}
	else {
		for (int i = 0; i < cand[now].size(); i++) {
			if (!ck[cand[now][i]])
			{
				ck[cand[now][i]] = 1;
				char ch = cand[now][i] + '0';
				dfs(cand, now + 1, ck, maked + ch);
				ck[cand[now][i]] = 0;
			}
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	n = banned_id.size();
	std::vector<bool> ck(user_id.size());
	std::vector<std::vector<int>> cand(n);
	for (int i = 0; i<banned_id.size(); i++)
		for (int j = 0; j < user_id.size(); j++) {
			if (check(banned_id[i], user_id[j])) cand[i].push_back(j);
		}
	dfs(cand, 0, ck, "");
	return answer;
}
int main() {
	vector<string> user_id,banned_id;
	user_id.push_back("frodo");
	user_id.push_back("fradi");
	user_id.push_back("crodo");
	user_id.push_back("abc123");
	user_id.push_back("frodoc");

	/*banned_id.push_back("fr*d*");
	banned_id.push_back("abc1**");*/
	banned_id.push_back("*rodo");
	banned_id.push_back("*rodo");
	banned_id.push_back("******");
	std::cout << solution(user_id, banned_id);
}