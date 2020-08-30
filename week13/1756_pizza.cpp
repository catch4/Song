/*
Catch study 12����
����_���ڿ� ����
https://www.acmicpc.net/problem/9935
*/
/*-----------------
Ʋ������
O(n2) ����

Ǯ��
�� �� �ִ� �ִ밪 ����,(���� �� �������� ����, �������� �ְ� �����ϸ� 70ms �� ����)
1. lower_bound�� ã�� -> 68ms
2. �׳� �������κк��� üũ �ϸ鼭 ã�� -> 60ms
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
