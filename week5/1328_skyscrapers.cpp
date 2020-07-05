/*
Catch study 5주차
백준_1328 고층 빌딩
https://www.acmicpc.net/problem/1328
*/
/*---------------------------
풀이
틀림.

3가지 케이스를 구하는 것 같은데
3번 케이스가 왜 저렇게 구해지는 지 모르겠음
1. i+1이 i 바로 오른쪽에
2. i+1이 i 바로 왼쪽에
3. 옆이 아닌 경우
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

				if (j + 1 <= l) { // 1. i+1이 i 바로 오른쪽에
					building[i + 1][j + 1][k] += tmp;
					building[i + 1][j + 1][k] %= MOD;
					std::cout << "(" << i + 1 << "," << j + 1 << "," << k << ")=" << building[i + 1][j + 1][k] << '\n';
				}
				if (k + 1 <= r) { // 2. i+1이 i 바로 왼쪽에
					building[i + 1][j][k + 1] += tmp;
					building[i + 1][j][k + 1] %= MOD;
					std::cout << "(" << i + 1 << "," << j<<"," << k+1 << ")=" << building[i + 1][j][k+1] << '\n';
				}
				building[i + 1][j][k] += tmp * (i - 1); // 3. 옆이 아닌 경우
				building[i + 1][j][k] %= MOD;
				std::cout << "(" << i + 1 << "," << j << "," << k << ")=" << building[i+1][j ][k] << '\n';

			}
		}
	}
	cout << building[n][l][r] << '\n';
	return 0;
}
