/*
Catch study 11주차
백준_가스관
https://www.acmicpc.net/problem/2931
*/
/*-----------------
풀이
브루트 포스
-----------------*/
#include <iostream>
#include <vector>
#include <string>
#define vec_2d_c std::vector<std::vector<char>>
int y, x, n, m, dx[] = { 0,1,0,-1 }, dy[] = { -1,0,1,0 };
char ch[4][4] = {
	{ '|','+','1','4' },
	{ '-','+','3','4' },
	{ '|','+','2','3' },
	{ '-','+','1','2' }
};

char search_pipe(vec_2d_c& map) {
	std::string tmp = "";
	for (int k = 0; k<4; k++) {
		int ny = y + dy[k], nx = x + dx[k];
		if (ny<0 || ny >= n || nx<0 || nx >= m) tmp += "0";
		else {
			bool flag = false;
			for (int z = 0; z<4; z++) {
				if (map[ny][nx] == ch[k][z]) {
					flag = true;
					break;
				}
			}
			if (flag) tmp += "1";
			else tmp += "0";
		}
	}
	if (tmp == "1111") return '+';
	else if (tmp == "1100") return '2';
	else if (tmp == "1010") return '|';
	else if (tmp == "1001") return '3';
	else if (tmp == "0110") return '1';
	else if (tmp == "0101") return '-';
	else if (tmp == "0011") return '4';
}

bool check(vec_2d_c& map, const int& i, const int& j) {
	char c = map[i][j];
	if (c == '|' || c == '+' || c == '2' || c == '3')
		if (map[i - 1][j] == '.')
		{
			y = i - 1, x = j;
			return true;
		}
	if (c == '|' || c == '+' || c == '1' || c == '4')
		if (map[i + 1][j] == '.')
		{
			y = i + 1, x = j;
			return true;
		}
	if (c == '-' || c == '+' || c == '3' || c == '4')
		if (map[i][j - 1] == '.')
		{
			y = i, x = j - 1;
			return true;
		}
	if (c == '-' || c == '+' || c == '1' || c == '2')
		if (map[i][j + 1] == '.')
		{
			y = i, x = j + 1;
			return true;
		}

	return false;
}

int main() {
	std::cin >> n >> m;
	vec_2d_c map(n, std::vector<char>(m, 0));
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			std::cin >> map[i][j];
	bool flag = false;
	for (int i = 0; i<n; i++) {
		if (flag) break;
		for (int j = 0; j<m; j++)
			if (map[i][j] != '.') {
				flag = check(map, i, j);
				if (flag) break;
			}
	}
	std::cout << y + 1 << " " << x + 1 << " " << search_pipe(map);

}
