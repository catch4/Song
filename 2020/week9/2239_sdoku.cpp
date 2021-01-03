/*
Catch study 9주차
백준_스도쿠
https://www.acmicpc.net/problem/2239
*/
/*-----------------
풀이
둘 때 마다 스도쿠 조건 확인, 백트래킹
-----------------*/

#include <iostream>
#include <vector>

int sdoku[9][9];
bool flag = false;


bool check(const int&y,const int& x) {
	int off_y = (y / 3) * 3, off_x = (x / 3) * 3;
	for (int i = 0; i < 9; i++) {
		if (i != x&&sdoku[y][x] == sdoku[y][i]) return false;
		if (i != y&&sdoku[y][x] == sdoku[i][x]) return false;
		int n_y = off_y + i / 3, n_x = off_x + i % 3;
		if (n_y == y&&n_x == x) continue;
		if (sdoku[y][x] == sdoku[n_y][n_x]) return false;
	}
	return true;
}

bool Do(const int& num) {

	if (num == 81)
	{
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				std::cout << sdoku[i][j];
			std::cout << '\n';
		}
		return true;
	}
	else {
		int y = num / 9, x = num % 9;
		if (sdoku[y][x]) {
			if(Do(num + 1)) return true;
		}
		else {
			for (int i = 1; i < 10; i++) {
				sdoku[y][x] = i;
				if(check(y,x))
					if(Do(num+1)) return true;
				sdoku[y][x] = 0;
			}
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			char num; std::cin >> num;
			sdoku[i][j]=num-'0';
		}
	Do(0);
	return 0;
}