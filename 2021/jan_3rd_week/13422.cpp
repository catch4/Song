/*
Catch study 21/jan/3week
백준_도둑
https://www.acmicpc.net/problem/13422

누적합 이용
m==n일 때에 대한 정보는 질문 검색 참고 함 ㅠㅠ
*/

#include <iostream>
#include <vector>
#define ll long long
int main() {
	int t; std::cin >> t;
	while (t--) {
		int n, m,cnt=0;
		ll k; std::cin >> n >> m >> k;
		std::vector<ll> vec(n + m);
		for (int i = 1; i < n+m; i++) {
			if (i <= n) {
				std::cin >> vec[i];
				if (i < m)
					vec[n + i] = vec[i];
			}
			vec[i] += vec[i - 1];
		}
		if (m == n) {
			if (vec[m] < k)
				std::cout << 1 << '\n';
			else
				std::cout << 0 << '\n';
		}
		else {
			for (int i = m; i < n + m; i++)
				if (vec[i] - vec[i - m] < k)
					cnt += 1;
			std::cout << cnt << '\n';
		}
	}
}