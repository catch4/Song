/*
Catch study 5����
����_14502 ������
https://www.acmicpc.net/problem/14502
*/
/*---------------------------
���Ʈ ������ bfs�� �����ߴ�.

1. �Է� ���� �� 1(��)�� ������ ���̷��� ��ġ�� �޴´�.
2. 3���� ���� ���� ��ġ�� ����. -> dfs (�ߺ����ϱ� ���� idx�������)
3. ���̷����� ������ ���� �ùķ��̼� -> bfs
3-1. �ùķ��̼� ���� ���������� �ִ밪��
     ����ũ�� - (ó�� 1�ǰ��� + ���� ���� ��) - ���̷�������
3-2. ���� ���������� ������ ����� �� �����϶� �ùķ��̼� ����
3-3. 3-2�� �ش����� ���� ��� �ִ밪 ����
---------------------------*/
#include <iostream>
#include <vector>
#include <queue>
#define pi std::pair<int,int>
#define vecs std::vector<std::vector<int>>
int one_num = 0, max = 0, n, m, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

//3.
void bfs(vecs& lab, std::queue<pi>& virous)
{
	std::queue<pi> Q = virous;
	vecs map = lab;
	int ret= (n*m) - (one_num + 3) - virous.size(); // 3-1.
	while (!Q.empty()) {
		pi now = Q.front();
		Q.pop();
		for (int k = 0; k < 4; k++)
		{
			int n_y = now.first + dy[k], n_x = now.second + dx[k];
			if (n_y >= 0 && n_y < n&&n_x >= 0 && n_x < m && !map[n_y][n_x])
			{
				map[n_y][n_x] = 2;
				Q.push({ n_y,n_x });
				ret -= 1;
				if (ret <= max) return; // 3-2.
			}
		}
	}
	max = ret; // 3-3.
}
// 2.
void dfs(vecs& lab, std::queue<pi>& virous, const int& choiced, const int& idx)
{
	if (choiced == 3) bfs(lab, virous);
	else
	{
		for (int i = idx; i < n*m; i++)
		{
			int y = i / m, x = i%m;
			if (!lab[y][x])
			{
				lab[y][x] = 1;
				dfs(lab, virous, choiced+1, idx + 1);
				lab[y][x] = 0;
			}
		}
	}
}

int main() {
	std::cin >> n >> m;
	vecs lab(n, std::vector<int>(m));
	std::queue<pi> virous;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			std::cin >> lab[i][j];
			// 1.
			if (lab[i][j] == 1) one_num += 1; 
			else if (lab[i][j] == 2) virous.push({ i,j });
		}
	dfs(lab, virous, 0, 0);
	std::cout << max << std::endl;
}