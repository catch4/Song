/*
Catch study 10주차
백준_수영장 만들기
https://www.acmicpc.net/problem/1113
*/
/*-----------------
풀이
물채우는 거는 bfs로 구현.

1. 이전에 성공한곳 안간다(comple 배열).
2. 이전에 실패한곳 안간다(ck 배열).
3. 1,2 제외한 곳중 방문했거나(visit 배열) h보다 높은곳 안간다.
4. 실패 여부 = ck 배열과 인접해있거나 n,m크기 벗어났을 때 실패로 판단

5. 현재 벽 높이를 wall 변수 기준으로 가능한거 + (answer 변수)
6. 5가 한번이라도 일어났으면 answer 변수를 ret 변수에 덧셈
-----------------*/

#include <iostream>
#include <vector>
#include <queue>
#define vec2d std::vector<std::vector<int>>
#define vec2d_b std::vector<std::vector<bool>>
#define pi std::pair<int,int>
#define pii std::pair<pi,int>
int n, m, answer = 0, dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 }, ret = 0;

void apply_ck(vec2d_b& ck, vec2d_b& visit) // visit은 적용되어 있는데 ck는 적용안된곳 적용
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visit[i][j]) ck[i][j] = 1;
}

bool bfs(vec2d& pool, vec2d_b& ck, const int& h, vec2d_b& comple) {
	// 초기 ck는 이전 comple들 모두 적용한거 1.
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