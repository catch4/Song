#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define pi std::pair<int,int>
int map[50][50], ch[10], mp[50][50];
int answer = 2147000000, n, m, dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 }, zero = 0;

std::vector<pi> virus;
std::vector<bool> ck;


void bfs() {
	memset(mp, -1, sizeof(mp));
	std::queue<pi> Q;
	for (int i = 0; i < m; i++) {
		Q.push(virus[ch[i]]);
		mp[virus[ch[i]].first][virus[ch[i]].second] = 0;
	}
	int max = 0, cnt = 0;
	while (!Q.empty()) {
		pi now = Q.front();
		Q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = now.first + dy[k], nx = now.second + dx[k];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || mp[ny][nx] != -1 || map[ny][nx] == 1) continue;

			mp[ny][nx] = mp[now.first][now.second] + 1;
			Q.push({ ny,nx });
			if (map[ny][nx] != 2) {
				cnt++;
				if (max<mp[ny][nx])
					max = mp[ny][nx];
				else if (max >= answer) return;
			}
		}
	}
	if (cnt != zero) return;
	answer = std::min(max, answer);
}

void dfs(const int& idx, const int& pre) {
	if (idx == m)
		bfs();
	else {
		for (int i = pre; i < virus.size(); i++)
		{
			if (ck[i]) continue;
			ck[i] = 1;
			ch[idx] = i;
			dfs(idx + 1, i);
			ck[i] = 0;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> m;

	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (!map[i][j])
				zero++;
		}

	if (!zero) {
		std::cout << 0 << '\n';
		return 0;
	}
	ck.resize(virus.size());
	dfs(0, 0);
	if (answer == 2147000000) std::cout << -1 << '\n';
	else std::cout << answer << '\n';
	return 0;
}