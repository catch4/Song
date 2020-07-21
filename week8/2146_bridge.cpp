/*
Catch study 8주차
백준_2146 다리 만들기
https://www.acmicpc.net/problem/2146
*/
/*-----------------------------
틀렸던 이유
BFS할 때 체크 배열 안함-> 시간초과

풀이
각 섬의 번호를 부여할때는 DFS
다리 놓을 때는 BFS

1. (DFS)섬이면서 섬 번호가 안붙여진 인접배열에 섬번호 부여.
2. (BFS)
   2-1. 섬 번호가 없는 경우(바다), 다리를 놓고 섬번호 부여
   2-2. 섬 번호가 다른 경우 
        현재 위치에서 다리놓은 개수와 해당 위치의 다리놓은 개수랑 현재 최소값 비교
------------------------------*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define vec_2d std::vector<std::vector<int>>
#define vec_2d_b std::vector<std::vector<bool>>
#define pi std::pair<int,int>
#define y first
#define x second
int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 },n,seg_cnt=1;

void segmentation(vec_2d& segment, vec_2d_b& land, // 1.
	const pi& now, std::queue<pi>& Q) {
	segment[now.y][now.x] = seg_cnt;
	int tmp_cnt = 0;
	for (int k = 0; k < 4; k++) {
		int n_y = now.y + dy[k], n_x = now.x + dx[k];
		if (n_y < 0 || n_y >= n|| n_x < 0 || n_x >= n) continue;
		if (land[n_y][n_x] && !segment[n_y][n_x]) {
			segmentation(segment, land, { n_y,n_x },Q);
		}
		if (segment[n_y][n_x] == seg_cnt) tmp_cnt += 1;
	}
	if(tmp_cnt<4)
		Q.push({ now });
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n; 
	vec_2d_b land(n, std::vector<bool> (n,0));
	vec_2d segment(n, std::vector<int> (n, 0));
	vec_2d cnt(n, std::vector<int>(n, 0));
	int answer = 2147000000;
	std::queue<pi> Q;
	for (int i = 0; i < n; i++) {
		int tmp;
		for (int j = 0; j < n; j++)
		{
			std::cin >> tmp;
			if (tmp) land[i][j] = 1;
		}
	}
	
	for (int i = 0; i < n; i++) { // 1.
		for (int j = 0; j < n; j++) {
			if (land[i][j] && !segment[i][j]) {
				segmentation(segment, land, { i,j },Q);
				seg_cnt += 1;
			}
		}
	}
	while (!Q.empty()) {
		pi now = Q.front();
		Q.pop();
		for (int k = 0; k < 4; k++) {
			int n_y = now.y + dy[k], n_x = now.x + dx[k];
			if (n_y < 0 || n_y >= n|| n_x < 0 || n_x >= n||segment[now.y][now.x]==segment[n_y][n_x]) continue;

			if (!segment[n_y][n_x]) { // 2-1.
				segment[n_y][n_x] = segment[now.y][now.x];
				cnt[n_y][n_x] = cnt[now.y][now.x] + 1;
				Q.push({ n_y,n_x });
			}
			else answer = std::min(answer, cnt[now.y][now.x] + cnt[n_y][n_x]); // 2-2.
		}
	}
	std::cout << answer;
}