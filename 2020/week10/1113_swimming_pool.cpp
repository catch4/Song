/*
Catch study 10����
����_������ �����
https://www.acmicpc.net/problem/1113
*/
/*-----------------
Ǯ��
��ä��� �Ŵ� bfs�� ����.

1. ������ �����Ѱ� �Ȱ���(comple �迭).
2. ������ �����Ѱ� �Ȱ���(ck �迭).
3. 1,2 ������ ���� �湮�߰ų�(visit �迭) h���� ������ �Ȱ���.
4. ���� ���� = ck �迭�� �������ְų� n,mũ�� ����� �� ���з� �Ǵ�

5. ���� �� ���̸� wall ���� �������� �����Ѱ� + (answer ����)
6. 5�� �ѹ��̶� �Ͼ���� answer ������ ret ������ ����
-----------------*/

#include <iostream>
#include <vector>
#include <queue>
#define vec2d std::vector<std::vector<int>>
#define vec2d_b std::vector<std::vector<bool>>
#define pi std::pair<int,int>
#define pii std::pair<pi,int>
int n, m, answer = 0, dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 }, ret = 0;

void apply_ck(vec2d_b& ck, vec2d_b& visit) // visit�� ����Ǿ� �ִµ� ck�� ����ȵȰ� ����
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visit[i][j]) ck[i][j] = 1;
}

bool bfs(vec2d& pool, vec2d_b& ck, const int& h, vec2d_b& comple) {
	// �ʱ� ck�� ���� comple�� ��� �����Ѱ� 1.
	answer = 0;
	bool flag = false;
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			int t_sum = 0;
			bool t_flag = 1;
			if (!ck[i][j] && pool[i][j]<h) // 2.
			{
				vec2d_b visit(n, std::vector<bool>(m, 0));
				visit[i][j] = 1;
				t_sum += h - pool[i][j];
				std::queue<pi> Q;
				Q.push({ i,j });
				while (!Q.empty()) {
					pi now = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int ny = now.first + dy[k], nx = now.second + dx[k];
						if (ny < 0 || ny >= n || nx < 0 || nx >= m || ck[ny][nx]) { // 4.
							while (!Q.empty()) {
								Q.pop();
							}
							t_flag = false;
							break;
						}
						if (visit[ny][nx] || pool[ny][nx] >= h) continue; // 3.
						visit[ny][nx] = 1;
						t_sum += h - pool[ny][nx];
						Q.push({ ny,nx });
					}
				}
				if (t_flag&&t_sum > 0) {
					answer += t_sum; // 5.
					apply_ck(comple, visit);
					flag = true;
				}
				apply_ck(ck, visit);
			}

		}
	return flag;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> m;
	vec2d pool(n, std::vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char ch; std::cin >> ch;
			pool[i][j] = ch - '0';
		}
	vec2d_b complete(n, std::vector<bool>(m, 0));
	for (int wall = 9; wall > 1; wall--) {
		vec2d_b ck = complete; // 1.
		if (bfs(pool, ck, wall, complete)) {
			ret += answer; // 6.
		}
	}
	std::cout << ret << '\n';
	return 0;
}