/*
Catch study 7����
����_1937 ������� �Ǵ�
https://www.acmicpc.net/problem/1937
*/
/*
Ǯ��
���� ��ġ�� ������ �ִ��� �˰� bfs�� Ǯ����
������ġ ���� 500x500 �̶� �켱���� ť�� dp�� Ǯ��

1. �볪������ ���� ���������� ����ȭ(�켱���� ť���)
2. dp �� �ֽ�ȭ
3. �ִ밪 �ֽ�ȭ
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pi std::pair<int,int>
#define y first
#define x second
struct Panda {
	pi pos;
	int cnt = 0;
	int day = 1;
	Panda() {}
	Panda(const pi& t_pos, const int& t_cnt, const int& t_day)
	{
		pos = t_pos, cnt = t_cnt, day = t_day;
	}
	bool operator<(const Panda& bb) const { // 1.
		if (cnt == bb.cnt) {
			return day < bb.day;
		}
		return cnt < bb.cnt;
	}
};
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };


int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n; std::cin >> n;
	int max = 1;
	std::vector<std::vector<int>> trees(n,std::vector<int> (n,0));
	std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
	std::priority_queue<Panda> Q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			std::cin >> trees[i][j];
			Q.push(Panda({ i,j }, trees[i][j], 1)); // 1.
		}
	
	while (!Q.empty()) {
		Panda now = Q.top();
		Q.pop();
		if (now.day > max) max = now.day;
		for (int k = 0; k < 4; k++) {
			int n_y = now.pos.y + dy[k], n_x = now.pos.x + dx[k];
			if (n_y < 0 || n_x < 0 || n_y >= n || n_x >= n) continue;
			if (now.cnt < trees[n_y][n_x]) // 2.
					dp[now.pos.y][now.pos.x] = std::max(dp[now.pos.y][now.pos.x], now.day + dp[n_y][n_x]);
		}
		// 2.
		dp[now.pos.y][now.pos.x] = std::max(dp[now.pos.y][now.pos.x], now.day);
		// 3.
		max = std::max(max, dp[now.pos.y][now.pos.x]);
	}
	std::cout << max << '\n';
}