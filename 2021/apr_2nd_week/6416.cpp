/*
Catch study 14/apr/2week
백준_트리인가?
https://www.acmicpc.net/problem/6416
*/
/*-----------------
풀이
노드 개수 0인 경우, in이 0개인 노드가 하나가 아닌 경우 체크
-----------------*/
#include <iostream>
#include <vector>
#include <map>
#define out first
#define in second
#define pi std::pair<int,int>

bool check(std::map<int, pi>& mp) {
	std::map<int, pi>::iterator iter;
	int zero_in = 0;
	for (iter = mp.begin(); iter != mp.end(); iter++) {
		if (!iter->second.in) { 
			zero_in += 1; 
			if (zero_in > 1) return false;
		}
		if (iter->second.in > 1) return false;
	}
	if (zero_in != 1) return false;
	return true;
}

int main() {
	int k = 0;
	bool exit_flag = false;
	while (1) {
		k++;
		int cnt = 0;
		std::map<int, pi> mp;
		while (1) {
			int p, c; std::cin >> p >> c;
			if (!p) break;
			if (p == -1) {
				exit_flag = true;
				break;
			}
			cnt += 1;
			if (mp.find(p) == mp.end())
				mp[p].out = 1;
			else mp[p].out += 1;

			if (mp.find(c) == mp.end())
				mp[c].in = 1;
			else mp[c].in += 1;
		}
		if (exit_flag) break;
		if (!cnt||check(mp))
			std::cout << "Case " << k << " is a tree.\n";
		else
			std::cout<< "Case " << k << " is not a tree.\n";
	}
}
