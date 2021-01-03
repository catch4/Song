/*
Catch study 7����
����_16236 �Ʊ���
https://www.acmicpc.net/problem/16236
*/
/*
bfs�� ����

1. ���̸� ���� �� ���� �� ���� bfs �ݺ�
2. ���� ����� ���̰� ���� �� ��� y,x Ȯ��
3. �Ծ����� �ش� ��ǥ���� �̵��� �ð� +
*/
#include <iostream>
#include <vector>
#include <queue>
#define vec2d std::vector<std::vector<int>>
#define pi std::pair<int,int>
#define pii std::pair<std::pair<int,int>,int>
#define y first
#define x second
int n,dy[4] = { 1,0,-1,0 },dx[4] = { 0,1,0,-1 };
int size = 2, time = 0;

bool bfs(vec2d& map, pi& shark) {
	std::queue<pii> Q;
	std::vector<pii> feed;
	std::vector<std::vector<bool>> ck(n, std::vector<bool> (n,0));
	Q.push({ shark,0 });
	ck[shark.y][shark.x] = 1;
	while (!Q.empty())
	{
		pi now = Q.front().first;
		int now_time = Q.front().second;
		Q.pop();
		if (feed.size() && feed[0].second <= now_time) continue;
		for (int k = 0; k < 4; k++) {
			pi n_pos = { now.y + dy[k],now.x + dx[k] };
			if (n_pos.y < n&&n_pos.y >= 0 && n_pos.x < n&&n_pos.x >= 0) {
				if (!ck[n_pos.y][n_pos.x] && map[n_pos.y][n_pos.x]&& map[n_pos.y][n_pos.x] < size) { // 2.
					ck[n_pos.y][n_pos.x] = 1;
					if (!feed.size())
						feed.push_back({ n_pos,now_time + 1 });
					else if (feed[0].first.y == n_pos.y)
					{
						if (feed[0].first.x > n_pos.x)
							feed[0].first = n_pos;
					}
					else if (feed[0].first.y > n_pos.y) feed[0].first = n_pos;
				}
				else if (!ck[n_pos.y][n_pos.x] && map[n_pos.y][n_pos.x]<=size) {
					ck[n_pos.y][n_pos.x] = 1;
					Q.push({ n_pos,now_time + 1 });
				}
				
			}
		}
	}
	if (feed.empty()) return false;
	time += feed[0].second; // 3.
	map[feed[0].first.y][feed[0].first.x] = 0;
	shark = feed[0].first;
	return true;
}

int main() {
	std::cin >> n;
	pi shark;
	vec2d map(n, std::vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 9) {
				shark = { i,j };
				map[i][j] = 0;
			}
		}
	int cnt = 0;
	while (bfs(map, shark)) { // 1.
		cnt++;
		if (cnt == size)
		{
			size++;
			cnt = 0;
		}
	}
	std::cout << time << std::endl;
	return 0;
}