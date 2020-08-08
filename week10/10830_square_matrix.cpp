/*
Catch study 10����
����_�������
https://www.acmicpc.net/problem/10830
*/
/*-----------------
Ǯ��

¦�� �϶� A^(n)*A^(n)
Ȧ�� �϶� E*A^(n)

-----------------*/

#include <iostream>
#include <vector>
#define vec2d std::vector<std::vector<int>>
int n;
long long m;
void matmul(vec2d& a, vec2d& b) { // ��İ�
	vec2d tmp(n, std::vector<int>(n, 0));

	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++) {
			int num = 0;
			for (int k = 0; k<n; k++)
			{
				num += a[i][k] * b[k][j];
				num %= 1000;
			}
			tmp[i][j] = num;
		}
	a = tmp;
}


int main() {
	std::cin >> n >> m;
	vec2d mat(n, std::vector<int>(n, 0)), ret(n, std::vector<int>(n, 0));

	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++) {
			std::cin >> mat[i][j];
			if (i == j) ret[i][j] = 1; // ret�� ó���� �׵���ķ�
		}

	while (m>0) {
		if (m % 2) {
			matmul(ret, mat);
		}
		m /= 2;
		matmul(mat, mat); // A^(N) ���·� ���� �� ���� ������ ��� ����
	}
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
			std::cout << ret[i][j] << " ";
		std::cout << '\n';
	}

	return 0;
}
