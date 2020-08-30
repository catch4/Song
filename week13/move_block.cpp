/*
Catch study 13����
���α׷��ӽ�_��� �̵��ϱ�
https://programmers.co.kr/learn/courses/30/lessons/60063
*/
/*-----------------
Ǯ��
�⺻�����δ� bfs�� y����,x ���� ������ �׻� �� 2���� ����, dy,dx�߰�
-----------------*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx11[4] = { 1,1,0,0 }, dx12[4] = { 0,0,-1,-1 }, dy11[4] = { -1,1,0,0 }, dy12[4] = { 0,0,-1,1 }; // ���� ������ ���
int dx21[4] = { -1,1,0,0 }, dx22[4] = { 0,0,-1,1 }, dy21[4] = { 1,1,0,0 }, dy22[4] = { 0,0,-1,-1 }; // ���� ������ ���

bool ck[100][100][100][100];

struct Pos {
	int y, x;
	Pos() {}
	Pos(const int& ty, const int& tx) {
		y = ty, x = tx;
	}
	bool operator<(const Pos& bb) {
		if (y == bb.y) return x < bb.x;
		else return y < bb.y;
	}
};

struct Info {
	Pos p1, p2;
	bool form = true; // true=����, false= ����
	int cnt = 0; // �̵� Ƚ��
	Info() {
		p1.y = 0, p1.x = 0, p2.y = 0, p2.x = 1;
	}
	Info(const Pos& tp1, const Pos& tp2, const bool& tf,const int& t_cnt)
	{
		p1 = tp1, p2 = tp2, form = tf,cnt=t_cnt;
	}
	void pos_check() {
		if (p2 < p1)
			std::swap(p1, p2);
	}
};

int solution(vector<vector<int>> board) {
	int answer = 0;
	int n = board.size()-1;
	ck[0][0][0][1] = 1;
	std::queue<Info> Q;
	Q.push(Info());
	while (!Q.empty()) {
		Info now = Q.front();
		Q.pop();
		for (int z = 0; z < 4; z++) { // �Ѵ� �����ϰ� �̵��� ��, ����� bfs ����
			int y1 = now.p1.y + dy[z],x1=now.p1.x+dx[z],y2=now.p2.y+dy[z],x2=now.p2.x+dx[z];
			if (y1 < 0 || y2 < 0 || x1 < 0 || x2 < 0 || y1 > n || y2 > n || x1 > n || x2 > n) continue;
			if (board[y1][x1] || board[y2][x2]) continue;
			if ((y1 == n&&x1 == n) || (y2 == n&&x2 == n)) return now.cnt + 1;
			Info nin(Pos(y1, x1), Pos(y2, x2), now.form, now.cnt + 1);
			nin.pos_check();
			if (ck[nin.p1.y][nin.p1.x][nin.p2.y][nin.p2.x]) continue;
			ck[nin.p1.y][nin.p1.x][nin.p2.y][nin.p2.x] = 1;
			Q.push(nin);
		}
		for (int z = 0; z < 4; z++) { // �� ���� �̵��� ���
			int y1, x1, y2, x2;
			if (now.form) { // ����� ���� ����� ��
				y1 = now.p1.y + dy11[z], x1 = now.p1.x + dx11[z];
				y2 = now.p2.y + dy12[z], x2 = now.p2.x + dx12[z];
			}
			else { // ����� ���� ����� ��
				y1 = now.p1.y + dy21[z], x1 = now.p1.x + dx21[z];
				y2 = now.p2.y + dy22[z], x2 = now.p2.x + dx22[z];
			}
			if (y1 < 0 || y2 < 0 || x1 < 0 || x2 < 0 || y1 > n || y2 > n || x1 > n || x2 > n) continue;
			if (board[y1][x1] || board[y2][x2]) continue;
			if (now.form) {// ȸ���� �߰��� ������ �ȵǴ� ���
				if (z < 2) {
					if (board[y1][now.p1.x]) continue; 
				}
				else {
					if (board[y2][now.p2.x]) continue;
				}
			}
			else {
				if (z < 2) {
					if (board[now.p1.y][x1]) continue;
				}
				else {
					if (board[now.p2.y][x2]) continue;
				}
			}
			if ((y1 == n&&x1 == n) || (y2 == n&&x2 == n)) return now.cnt + 1; // ������ ���
			Info nin(Pos(y1, x1), Pos(y2, x2), 1-now.form, now.cnt + 1);
			nin.pos_check(); // �׻� ���̰ų� ���ʿ� �ִ� point�� p1,�Ʒ��ų� �������� point�� p2 
			if (ck[nin.p1.y][nin.p1.x][nin.p2.y][nin.p2.x]) continue; // �Դ� ���� ���� �ʴ´�.
			ck[nin.p1.y][nin.p1.x][nin.p2.y][nin.p2.x] = 1; // �湮 üũ
			Q.push(nin);
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> board = { {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} };
	std::cout << solution(board);
}