/*
Catch study 3주차
백준_5373 큐빙
https://www.acmicpc.net/problem/5373
*/
/*
w
rbog
y
로 두고 시뮬레이션 진행

0. 각 색깔로 초기화
1-1. 기준이 되는 부분 시계(di=true) 방향, 반시계 방향 회전
1-2. 기준 주변 회전

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
char color[6] = { 'w','r','b','o','g','y' };
struct Board {
	char board[3][3];
};

void rot_board(Board& board, bool di) { // 1-1.
	Board tmp_board = board;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (di)
				board.board[i][j] = tmp_board.board[2 - j][i];
			else
				board.board[i][j] = tmp_board.board[j][2 - i];
		}
}

struct Cube {
	Board cube_board[6];
	Cube() { // 0.
		for (int c = 0; c < 6; c++)
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					cube_board[c].board[i][j] = color[c];
	}
	void rot(std::string cmd) { // 1-2.
		if (cmd[0] == 'L')
		{
			char tmp;
			int idxs[4];
			if (cmd[1] == '+') {
				idxs[0] = 3, idxs[1] = 5, idxs[2] = 1, idxs[3] = 0;
				rot_board(cube_board[4], 1);
			}
			else {
				idxs[0] = 3, idxs[1] = 0, idxs[2] = 1, idxs[3] = 5;
				rot_board(cube_board[4], 0);
			}
			for (int i = 0; i < 3; i++)
			{
				tmp = cube_board[idxs[0]].board[2 - i][2];
				cube_board[idxs[0]].board[2 - i][2] = cube_board[idxs[1]].board[i][0];
				cube_board[idxs[1]].board[i][0] = cube_board[idxs[2]].board[i][0];
				cube_board[idxs[2]].board[i][0] = cube_board[idxs[3]].board[i][0];
				cube_board[idxs[3]].board[i][0] = tmp;
			}

		}
		else if (cmd[0] == 'R')
		{
			char tmp;
			int idxs[4];
			if (cmd[1] == '+') {
				idxs[0] = 3, idxs[1] = 0, idxs[2] = 1, idxs[3] = 5;
				rot_board(cube_board[2], 1);
			}
			else {
				idxs[0] = 3, idxs[1] = 5, idxs[2] = 1, idxs[3] = 0;
				rot_board(cube_board[2], 0);
			}
			for (int i = 0; i < 3; i++)
			{
				tmp = cube_board[idxs[0]].board[2 - i][0];
				cube_board[idxs[0]].board[2 - i][0] = cube_board[idxs[1]].board[i][2];
				cube_board[idxs[1]].board[i][2] = cube_board[idxs[2]].board[i][2];
				cube_board[idxs[2]].board[i][2] = cube_board[idxs[3]].board[i][2];
				cube_board[idxs[3]].board[i][2] = tmp;
			}
		}
		else if (cmd[0] == 'U') {
			char tmp;
			int idxs[4];
			if (cmd[1] == '+') {
				idxs[0] = 1, idxs[1] = 2, idxs[2] = 3, idxs[3] = 4;
				rot_board(cube_board[0], 1);
			}
			else {
				idxs[0] = 1, idxs[1] = 4, idxs[2] = 3, idxs[3] = 2;
				rot_board(cube_board[0], 0);
			}
			for (int i = 0; i < 3; i++)
			{
				tmp = cube_board[idxs[0]].board[0][i];
				cube_board[idxs[0]].board[0][i] = cube_board[idxs[1]].board[0][i];
				cube_board[idxs[1]].board[0][i] = cube_board[idxs[2]].board[0][i];
				cube_board[idxs[2]].board[0][i] = cube_board[idxs[3]].board[0][i];
				cube_board[idxs[3]].board[0][i] = tmp;
			}
		}
		else if (cmd[0] == 'D') {
			char tmp;
			int idxs[4];
			if (cmd[1] == '+') {
				idxs[0] = 1, idxs[1] = 4, idxs[2] = 3, idxs[3] = 2;
				rot_board(cube_board[5], 1);
			}
			else {
				idxs[0] = 1, idxs[1] = 2, idxs[2] = 3, idxs[3] = 4;
				rot_board(cube_board[5], 0);
			}
			for (int i = 0; i < 3; i++)
			{
				tmp = cube_board[idxs[0]].board[2][i];
				cube_board[idxs[0]].board[2][i] = cube_board[idxs[1]].board[2][i];
				cube_board[idxs[1]].board[2][i] = cube_board[idxs[2]].board[2][i];
				cube_board[idxs[2]].board[2][i] = cube_board[idxs[3]].board[2][i];
				cube_board[idxs[3]].board[2][i] = tmp;
			}
		}
		else if (cmd[0] == 'F')
		{
			char tmp;
			if (cmd[1] == '+') {
				for (int i = 0; i < 3; i++)
				{
					tmp = cube_board[0].board[2][i];
					cube_board[0].board[2][i] = cube_board[4].board[2-i][2];
					cube_board[4].board[2-i][2] = cube_board[5].board[0][2-i];
					cube_board[5].board[0][2-i] = cube_board[2].board[i][0];
					cube_board[2].board[i][0] = tmp;
				}
				rot_board(cube_board[1], 1);
			}
			else {
				for (int i = 0; i < 3; i++)
				{
					tmp = cube_board[0].board[2][i];
					cube_board[0].board[2][i] = cube_board[2].board[i][0];
					cube_board[2].board[i][0] = cube_board[5].board[0][2-i];
					cube_board[5].board[0][2-i] = cube_board[4].board[2-i][2];
					cube_board[4].board[2-i][2] = tmp;
				}
				rot_board(cube_board[1], 0);
			}
		}
		else {
			char tmp;
			if (cmd[1] == '+') {
				for (int i = 0; i < 3; i++)
				{
					tmp = cube_board[0].board[0][i];
					cube_board[0].board[0][i] = cube_board[2].board[i][2];
					cube_board[2].board[i][2] = cube_board[5].board[2][2-i];
					cube_board[5].board[2][2-i] = cube_board[4].board[2-i][0];
					cube_board[4].board[2-i][0] = tmp;
				}
				rot_board(cube_board[3], 1);
			}
			else {
				for (int i = 0; i < 3; i++)
				{
					tmp = cube_board[0].board[0][i];
					cube_board[0].board[0][i] = cube_board[4].board[2-i][0]; 
					cube_board[4].board[2-i][0] = cube_board[5].board[2][2 - i];
					cube_board[5].board[2][2 - i] = cube_board[2].board[i][2];
					cube_board[2].board[i][2] = tmp;
				}
				rot_board(cube_board[3], 0);
			}
		}
	}
	void print()
	{
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				std::cout << cube_board[0].board[i][j];
			std::cout << '\n';
		}
	}
};

int main() {
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		std::string str;
		Cube cube;
		while (n--)
		{
			std::cin >> str;
			cube.rot(str);
		}
		cube.print();
	}
}