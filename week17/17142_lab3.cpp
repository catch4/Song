//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//#define pi std::pair<int,int>
//#define vec2d std::vector<std::vector<int>>
//int answer = 2147000000, n, m, dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 },zero=0;
//std::vector<int> ch;
//std::vector<pi> virus;
//std::vector<bool> ck;
//
//
//void bfs(vec2d& map) {
//	int mp[50][50];
//	memset(mp, -1, sizeof(mp));
//	std::queue<pi> Q;
//	for (int i = 0; i < m; i++) {
//		Q.push(virus[ch[i]]);
//		mp[virus[ch[i]].first][virus[ch[i]].second] = 0;
//	}
//	int max = 0,cnt=0;
//	while (!Q.empty()) {
//		pi now = Q.front();
//		Q.pop();
//		for (int k = 0; k < 4; k++) {
//			int ny = now.first + dy[k],nx = now.second + dx[k];
//			if (ny < 0 || ny >= n || nx < 0 || nx >= n || mp[ny][nx]!=-1||map[ny][nx]) continue;
//			mp[ny][nx] = mp[now.first][now.second] + 1;
//			Q.push({ ny,nx });
//			cnt++;
//			if (max<mp[ny][nx])
//				max = mp[ny][nx];
//			else if (max >= answer) return;
//		}
//	}
//	if (cnt != zero) return;
//	if (max < answer) 
//		answer = max;
//}
//
//void dfs(const int& idx,vec2d& mp) {
//	if (idx == m)
//		bfs(mp);
//	else {
//		for (int i = 0; i < virus.size(); i++)
//		{
//			if (!ck[i]) {
//				ck[i] = 1;
//				ch[idx] = i;
//				dfs(idx + 1, mp);
//				ck[i] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//	std::cin >> n >> m;
//	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
//	ch.resize(m);
//	vec2d mp(n, std::vector<int>(n, 0));
//	for(int i=0;i<n;i++)
//		for (int j = 0; j < n; j++) {
//			std::cin >> mp[i][j];
//			if (mp[i][j] == 2){
//				virus.push_back({ i,j });
//			}
//			else if (!mp[i][j])
//				zero++;
//		}
//	
//	if (!zero) {
//		std::cout << 0 << '\n';
//		return 0;
//	}
//	ck.resize(virus.size());
//	dfs(0, mp);
//	if (answer == 2147000000) std::cout << -1 << '\n';
//	else std::cout << answer << '\n';
//	return 0;
//}

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define pi std::pair<int,int>
int map[50][50],ch[10],mp[50][50];
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
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || mp[ny][nx] != -1 || map[ny][nx]) continue;
			mp[ny][nx] = mp[now.first][now.second] + 1;
			Q.push({ ny,nx });
			cnt++;
			if (max<mp[ny][nx])
				max = mp[ny][nx];
			else if (max >= answer) return;
		}
	}
	if (cnt != zero) return;
	if (max < answer)
		answer = max;
}

void dfs(const int& idx) {
	if (idx == m)
		bfs();
	else {
		for (int i = 0; i < virus.size(); i++)
		{
			if (!ck[i]) {
				ck[i] = 1;
				ch[idx] = i;
				dfs(idx + 1);
				ck[i] = 0;
			}
		}
	}
}

int main() {
	std::cin >> n >> m;
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

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
	dfs(0);
	if (answer == 2147000000) std::cout << -1 << '\n';
	else std::cout << answer << '\n';
	return 0;
}