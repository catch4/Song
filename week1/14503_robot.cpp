/*
Catch study 1����
����_14503 �κ�û�ұ�
https://www.acmicpc.net/problem/14503
*/
#include <iostream>
#include <vector>

int main() {
	int n, m,d,n_d,y,x,cnt=1,rot_cnt=0; 

	// �ϵ�����
	int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };

	std::cin >> n >> m>>y>>x>>d;
	std::vector<std::vector<int>> ck(n, std::vector<int>(m,0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> ck[i][j];
	ck[y][x] = 2;

	while (1)
	{
      // 4�� ȸ�� �� ���
		if (rot_cnt == 4)
		{
			int n_d = (d + 2) % 4;
			int n_y = y + dy[n_d], n_x = x + dx[n_d];
          // �ڿ� ���̰ų� ���� ��� while�� Ż��
			if (n_y < 0 || n_y >= n || n_x < 0 || n_x >= m || ck[n_y][n_x] == 1) break;
			y = n_y;
			x = n_x;
			rot_cnt = 0;
			continue;
		}
      // ���� ����
		if (!d) d = 3;
		else d -= 1;
		int n_y = y + dy[d], n_x = x + dx[d];
		
		// ������ û�� �Ұ����� ���
		if (n_y < 0 || n_y >= n || n_x < 0 || n_x >= m || ck[n_y][n_x])
			rot_cnt++;
		else // ������ û�� ������ ���
		{
			rot_cnt = 0;
			ck[n_y][n_x] = 2;
			cnt++;
			y = n_y;
			x = n_x;
		}
	}
	std::cout << cnt;

	return 0;
}
