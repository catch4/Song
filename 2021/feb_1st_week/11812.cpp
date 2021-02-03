/*
Catch study 21/feb/1week
����_K�� Ʈ��
https://www.acmicpc.net/problem/11812
*/
/*-----------------
Ǯ��
abs ���� Ʋ���ٰ� ���´�.
�θ��� ���ϴ� ������ ���ͳ��� �����Ͽ���.
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