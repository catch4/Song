/*
Catch study 12주차
백준_문자열 폭발
https://www.acmicpc.net/problem/9935
*/
/*-----------------
틀린이유
O(n2) 실패

풀이
들어갈 수 있는 최대값 갱신,(넣을 때 역순으로 넣음, 정순으로 넣고 솔팅하면 70ms 대 나옴)
1. lower_bound로 찾음 -> 68ms
2. 그냥 마지막부분부터 체크 하면서 찾음 -> 60ms
-----------------*/

// 68ms
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, m, min, num, com = 0; std::cin >> n >> m;
	std::vector<int> oven(n);
	std::cin >> oven[n - 1];
	min = oven[n - 1];
	bool fail = false;
	for (int i = n - 2; i >= 0; i--) {
		std::cin >> num;
		oven[i] = std::min(num, oven[i + 1]);
	}
	for (int j = 0; j < m; j++) {
		std::cin >> num;
		if (com == n) {
			fail = true;
			break;
		}
		com = std::lower_bound(oven.begin() + com, oven.end(), num) - oven.begin() + 1;
	}
	if (fail) std::cout << 0 << '\n';
	else std::cout << n - com + 1 << '\n';
}


// 60ms
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m, min, num, com; std::cin >> n >> m; com = n;
	std::vector<int> oven(n);
	std::cin >> oven[0];
	min = oven[0];
	bool fail = false;
	for (int i = 1; i <n; i++) {
		std::cin >> num;
		oven[i] = std::min(num, oven[i - 1]);
	}
	for (int i = 0; i < m; i++) {
		std::cin >> num;
		if (com<=0) {
			fail = true;
			break;
		}
		for (int k = com-1; k >= 0; k--)
			if (oven[k] >= num)
			{
				com = k;
				break;
			}
			else if (k == 0) com = -1;
	}
	if (fail) std::cout << 0 << '\n';
	else std::cout << com + 1 << '\n';
}
