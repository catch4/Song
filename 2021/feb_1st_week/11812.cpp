/*
Catch study 21/feb/1week
백준_K진 트리
https://www.acmicpc.net/problem/11812
*/
/*-----------------
풀이
abs 쓰면 틀리다고 나온다.
부모노드 구하는 공식은 인터넷을 참고하였다.
-----------------*/
#include <iostream>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	long long  n;
	int k, q; std::cin >> n >> k >> q;
	while (q--) {
		long long a, b, cnt = 0; std::cin >> a >> b;
		if (k == 1) {
			if (a <= b) std::cout << b - a << '\n';
			else std::cout << a - b << '\n';
		}
		else {
			while (a != b) {
				if (a < b)
					b = (b - 2) / k + 1;
				else
					a = (a - 2) / k + 1;
				cnt += 1;
			}
			std::cout << cnt << '\n';
		}
	}
	return 0;
}