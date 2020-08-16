/*
Catch study 11����
����_��ũ Ʈ��
https://www.acmicpc.net/problem/7432
*/
/*-----------------
Ǯ��
�����ؼ� print ����
root directory ��¿��δ� �ؽ��� Ȯ��
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