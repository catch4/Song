/*
Catch study 12주차
백준_cubeditor
https://www.acmicpc.net/problem/1701
*/
/*-----------------
풀이 - 틀림

1. 첫번째 문자부터 확인
2. kmp로 동일한 부분 체크하면서 max값 최신화
-----------------*/
#include <iostream>
#include <vector>
#include <string>
int ans, n, pi[5001];
std::string t;

int main() {
	std::cin.sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> t;
	for (int i = 0; i<t.size(); i++) {
		int k = 0;
		for (int j = i + 1; j<t.size(); j++) {
			while (k > 0 && t[j] != t[i + k]) k = pi[k - 1]; // kmp
			if (t[j] == t[i + k]) {
				k++;
				if (ans < k)ans = k;
			}
			pi[j - i] = k; // 접두어와 접미사가 동일한 길이 체크
		}
	}
	std::cout << ans;
}