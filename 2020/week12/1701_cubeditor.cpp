/*
Catch study 12����
����_cubeditor
https://www.acmicpc.net/problem/1701
*/
/*-----------------
Ǯ�� - Ʋ��

1. ù��° ���ں��� Ȯ��
2. kmp�� ������ �κ� üũ�ϸ鼭 max�� �ֽ�ȭ
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
			pi[j - i] = k; // ���ξ�� ���̻簡 ������ ���� üũ
		}
	}
	std::cout << ans;
}