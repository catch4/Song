/*
Catch study 8����
����_1956 �
https://www.acmicpc.net/problem/1956
*/
/*-----------------------------
Ʋ�ȴ�����
"�Ұ����� �� -1�� ����Ѵ�" ������

Ǯ��
�÷��̵� �ͼ��� ǰ

1. ���� ��� �ֽ�ȭ
2. ������� ���ƿ� ��� answer �ֽ�ȭ
------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147000000
int n,m,answer=INF;

int main() {
	std::cin >> n>>m;
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::vector<std::vector<int>> min_c(n, std::vector<int>(n, INF));
	for (int i = 0; i < m; i++) {
		int a, b, c; std::cin >> a >> b >> c;
		min_c[a - 1][b - 1] = c;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				if (min_c[i][j] == INF || min_c[j][k] == INF) continue;
				min_c[i][k] = std::min(min_c[i][k], min_c[i][j] + min_c[j][k]); // 1.
				if (i == k) answer = std::min(answer,min_c[i][k]); // 2.
			}
	if (answer == INF) std::cout << -1 << '\n';
	else std::cout << answer << '\n';
	return 0;
}