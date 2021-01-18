/*
Catch study 21/jan/3week
����_����
https://www.acmicpc.net/problem/13422

������ �̿�
m==n�� ���� ���� ������ ���� �˻� ���� �� �Ф�
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