/*
Catch study 12����
����_����
https://www.acmicpc.net/problem/3109
*/
/*-----------------
Ǯ��
1. ������ ���� Ȯ���ϰ� ���� ���� ���� ������ ������� ���� �ʴ´�.
2. ���� �� �� �� �̻� Ž������ �ʴ´�.
-----------------*/
#include <iostream>
#include <vector>
char mp[10000][500];
bool ck[10000][500];
int n, m, dx[3] = { 1,1,1 }, dy[3] = { -1,0,1 },answer;

bool dfs(const int& i,const int& j) {
	if (j == m - 1) {
		answer += 1;
		return true;
	}
	else {
		for (int k = 0; k < 3; k++) {
			int y = i + dy[k], x = j + dx[k];
			if (y < 0 || y >= n || ck[y][x]||mp[y][x]=='x') continue;
			ck[y][x] = 1; // 1.
			if(dfs(y, x)) return true; // 2.
		}
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> mp[i][j];

	for (int i = 0; i < n; i++)
		if (mp[i][0] != 'x')
			dfs(i, 0);
	std::cout << answer << '\n';
}