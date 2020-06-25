/*
Catch study 4����
����_13460 ���� Ż�� 2
https://www.acmicpc.net/problem/13460
*/
/*
bfs�� ���� �ߴµ� �̵��ϴ� ����� ���� ���� ��� �ۼ��� �� ����.

1. Bead ����ü
1-1. ���� ��ġ
1-2. �Ķ����� ���ۿ� ���� -1, �̵����� 0, �������� ���ۿ� ���� 1
1-3. ������ ȸ���� ����,������ ȸ���� �������� ȸ���ص� ���ϴ°� ����
1-4. ȸ�� Ƚ��

2. ȸ��
2-1. ȸ���ϴ� ���� �������� yȤ�� x�� ���� ��� �Ǵ�.
2-2. yȤ�� x�� ���� ��� ���� ���� �� �̵�
2-3. �ƴ� ��� �Ķ��� ���� �̵�
*/
#include <iostream>
#include <vector>
#include <queue>
#define vecs_c std::vector<std::vector<char>>
#define y first
#define x second
int n, m, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
struct Bead {
	std::pair<int, int> red, blue; // 1-1.
	int flag = 0; // 1-2.
	int rot_num = 0; // 1-3.
	int rot = 0; // 1-4.
	Bead(){}
	Bead(const Bead& bb) {
		red = bb.red; blue = bb.blue,flag=bb.flag,rot_num=bb.rot_num,rot=bb.rot;
	}
};

bool judge(const int& rot, Bead& bead) {
	if (!dy[rot - 1] && (bead.red.y == bead.blue.y)) return true;
	else if (!dx[rot - 1] && (bead.red.x == bead.blue.x)) return true;
	return false;
}

Bead rotate_box(vecs_c& box,Bead& bead, const int& rot) {
	Bead tmp(bead);
	// 2-1.
	if (judge(rot, tmp)) { //2-2.
		std::pair<int, int> *pre, *post;
		bool flag;
		if (dx[rot - 1]) {
			if (dx[rot - 1] > 0)
			{
				pre = (tmp.blue.x > tmp.red.x) ? &tmp.blue : &tmp.red;
				post = (tmp.blue.x > tmp.red.x) ? &tmp.red : &tmp.blue;
				flag = (tmp.blue.x > tmp.red.x) ? false : true;
			}
			else {
				pre = (tmp.blue.x < tmp.red.x) ? &tmp.blue : &tmp.red;
				post = (tmp.blue.x < tmp.red.x) ? &tmp.red : &tmp.blue;
				flag = (tmp.blue.x < tmp.red.x) ? false : true;
			}
		}
		else {
			if (dy[rot - 1] > 0)
			{
				pre = (tmp.blue.y > tmp.red.y) ? &tmp.blue : &tmp.red;
				post = (tmp.blue.y > tmp.red.y) ? &tmp.red : &tmp.blue;
				flag = (tmp.blue.y > tmp.red.y) ? false : true;
			}
			else {
				pre = (tmp.blue.y < tmp.red.y) ? &tmp.blue : &tmp.red;
				post = (tmp.blue.y < tmp.red.y) ? &tmp.red : &tmp.blue;
				flag = (tmp.blue.y < tmp.red.y) ? false : true;
			}
		}
		while (pre->x>0 && pre->x<m-1 && pre->y>0 && pre->y <n-1)
		{
			int n_y = pre->y + dy[rot - 1],n_x = pre->x + dx[rot - 1];
			if (box[n_y][n_x] == '#') break;	
			if (box[n_y][n_x] == 'O')
			{
				if (flag)
					tmp.flag = 1;
				else 
					tmp.flag = -1;
				pre->y = 0, pre->x = 0;
				break;
			}
			else
			{
				pre->y = n_y;
				pre->x = n_x;
			}
		}
		if (tmp.flag==-1) return tmp;
		while (post->x>0 && post->x<m - 1 && post->y>0 && post->y <n - 1)
		{
			int n_y = post->y + dy[rot - 1], n_x = post->x + dx[rot - 1];
			if (box[n_y][n_x] == '#'|| (n_y == pre->y&&n_x==pre->x)) break;
			if (box[n_y][n_x] == 'O')
			{
				if (!flag)
					tmp.flag = 1;
				else
					tmp.flag = -1;
				break;
				
			}
			else
			{
				post->y = n_y;
				post->x = n_x;
			}
		}
	}
	else { //2-3.
		bool flag_blue = true, flag_red = true;
		while (flag_blue || flag_red)
		{
			if (flag_blue)
			{
				int n_y = tmp.blue.y + dy[rot - 1], n_x = tmp.blue.x + dx[rot - 1];
				if (box[n_y][n_x] == '#' || n_y == 0 || n_y == n - 1 || n_x == 0 || n_x == m - 1)
					flag_blue = false;
				else if (box[n_y][n_x] == 'O')
				{
					tmp.flag = -1;
					return tmp;
				}
				else
				{
					tmp.blue.y = n_y; tmp.blue.x = n_x;
				}
			}
			if (flag_red)
			{
				int n_y = tmp.red.y + dy[rot - 1], n_x = tmp.red.x + dx[rot - 1];
				if (box[n_y][n_x] == '#' || n_y == 0 || n_y == n - 1 || n_x == 0 || n_x == m - 1)
					flag_red = false;
				else if (box[n_y][n_x] == 'O') {
					tmp.flag = 1;
					flag_red = false;
				}
				else
				{
					tmp.red.y = n_y; tmp.red.x = n_x;
				}
			}
		}
	}

	return tmp;
}

int main() {
	std::cin >> n >> m;
	vecs_c box(n, std::vector<char>(m));
	Bead bead;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			std::cin >> box[i][j];
			if (box[i][j] == 'R')
			{
				box[i][j] = '.';
				bead.red = { i,j };
			}
			else if (box[i][j] == 'B')
			{
				box[i][j] = '.';
				bead.blue = { i,j };
			}
		}
	std::queue<Bead> Q;
	Q.push(bead);
	while (!Q.empty())
	{
		Bead now = Q.front();
		Q.pop();
		for (int i = 1; i <= 4; i++)
		{
			if (now.rot == i) continue;
			Bead tmp(rotate_box(box, now, i));
			if (tmp.flag == 1) {
				std::cout << now.rot_num + 1;
				return 0;
			}
			if (!tmp.flag && now.rot_num<9 &&
				(now.blue.y!=tmp.blue.y|| now.blue.x != tmp.blue.x ||
					now.red.y != tmp.red.y || now.red.x != tmp.red.x))
			{
				tmp.rot_num = now.rot_num+1;
				tmp.rot = i;
				Q.push(tmp);
			}
		}
	}
	std::cout << -1 << std::endl;
	return 0;
}