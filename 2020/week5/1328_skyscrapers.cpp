/*
Catch study 5����
����_1328 ���� ����
https://www.acmicpc.net/problem/1328
*/
/*---------------------------
Ǯ��
Ʋ��.

3���� ���̽��� ���ϴ� �� ������
3�� ���̽��� �� ������ �������� �� �𸣰���
1. i+1�� i �ٷ� �����ʿ�
2. i+1�� i �ٷ� ���ʿ�
3. ���� �ƴ� ���
---------------------------*/
#include <iostream>
using namespace std;
#define MOD 1000000007;
long long building[101][101][101];
int main() {
	int n, l, r;
	cin >> n >> l >> r;
	building[1][1][1] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= l; j++)
		{
			for (int k = 1; k <= r; k++)
			{
				long long tmp = building[i][j][k];
				std::cout << "\nwhen (" << i << "," << j << "," << k << ") = " <<tmp<< '\n';

				if (j + 1 <= l) { // 1. i+1�� i �ٷ� �����ʿ�
					building[i + 1][j + 1][k] += tmp;
					building[i + 1][j + 1][k] %= MOD;
					std::cout << "(" << i + 1 << "," << j + 1 << "," << k << ")=" << building[i + 1][j + 1][k] << '\n';
				}
				if (k + 1 <= r) { // 2. i+1�� i �ٷ� ���ʿ�
					building[i + 1][j][k + 1] += tmp;
					building[i + 1][j][k + 1] %= MOD;
					std::cout << "(" << i + 1 << "," << j<<"," << k+1 << ")=" << building[i + 1][j][k+1] << '\n';
				}
				building[i + 1][j][k] += tmp * (i - 1); // 3. ���� �ƴ� ���
				building[i + 1][j][k] %= MOD;
				std::cout << "(" << i + 1 << "," << j << "," << k << ")=" << building[i+1][j ][k] << '\n';

			}
		}
	}
	cout << building[n][l][r] << '\n';
	return 0;
}
