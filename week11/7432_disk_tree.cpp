/*
Catch study 11주차
백준_디스크 트리
https://www.acmicpc.net/problem/7432
*/
/*-----------------
풀이
정렬해서 print 찍음
root directory 출력여부는 해쉬로 확인
-----------------*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
struct Dir {
	std::vector<std::string> st;
	bool operator<(const Dir& bb) {
		int len = std::min(st.size(), bb.st.size());
		for (int i = 0; i < len; i++) {
			if (st[i] != bb.st[i])
				return st[i] < bb.st[i];
		}
		return st.size() < bb.st.size();
	}
};
std::unordered_map<std::string, bool> mp;

void print(Dir& dir) {
	std::string str="";
	for (int i = 0; i < dir.st.size(); i++)
	{
		str += dir.st[i];
		if (!mp[str])
		{
			mp[str] = 1;
			for (int j = 0; j < i; j++)
				std::cout << ' ';
			std::cout << dir.st[i]<<'\n';
		}
		str += "\\";
	}
}

int main() {
	int n; std::cin >> n;
	std::vector<Dir> dir(n);
	for (int i = 0; i < n; i++) {
		std::string s, tmp = "";
		std::cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '\\') {
				dir[i].st.push_back(tmp);
				tmp = "";
			}
			else
				tmp += s[j];
		}
		dir[i].st.push_back(tmp);
	}
	sort(dir.begin(), dir.end());

	for (int i = 0; i < n; i++)
		print(dir[i]);
}