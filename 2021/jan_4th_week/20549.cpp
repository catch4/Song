/*
Catch study 21/jan/4week
백준_20549 인덕이의 고민
https://www.acmicpc.net/problem/20549

먹이 먹은 조합을 비트마스킹, 현재 맵에 먹이 조합 + penalty로 ck
우선순위 큐 사용해서 제일 먼저 모든 먹이를 먹는 경우 return
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define vec2d std::vector<std::vector<int>>
#define pi std::pair<int,int>
#define x first
#define y second
int penalty[3], ck[50][50][16];

struct Duck{
	Duck() {}
	Duck(const pi& ppos, const int& pp, const int& ppenal, const int& c) { pos = ppos, p = pp, penal = ppenal,cnt=c; }
	pi pos;
	int p=0, penal=0,cnt=0;
	bool operator<(const Duck& bb)const {
		return penal > bb.penal;
	}
};
int knight_x1[8] = { 2,2,0,0,-2,-2,0,0 }, knight_y1[8] = { 0,0,2,2,0,0,-2,-2 };
int knight_x2[8] = { 0,0,1,-1,0,0,-1,1 }, knight_y2[8] = { 1,-1,0,0,1,-1 };

int bishop_x[4] = { 1,1,-1,-1 }, bishop_y[4] = { -1,1,1,-1 };
int rook_x[4] = { 1,0,-1,0 }, rook_y[4] = { 0,1,0,-1 };

int main() {
	memset(ck, 0x7f,sizeof(ck));
	int n,m; std::cin >> n;
	vec2d vec(n, std::vector<int>(n, 0));
	for (int i = 0; i < 3; i++) std::cin >> penalty[i];
	std::priority_queue<Duck> Q;
	Duck d;
	std::cin >> d.pos.x >> d.pos.y>>m;
	Q.push(d);
	std::vector<pi> feed(m);
	for (int i = 0; i < m; i++) {
		std::cin >> feed[i].x >> feed[i].y;
	}
	
	while (!Q.empty()) {
		Duck now = Q.top();
		Q.pop();

		if (now.p == ((1 << m) - 1)) {
			std::cout << now.penal;
			return 0;
		}
		if (ck[now.pos.y][now.pos.x][now.p] <= now.penal) continue;
		ck[now.pos.y][now.pos.x][now.p] = now.penal;

		// knight
		for (int z = 0; z < 8; z++) {
			int xx = now.pos.x + knight_x1[z] + knight_x2[z], yy = now.pos.y + knight_y1[z] + knight_y2[z];
			if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
			bool flag = false;
			for (int f = 0; f < m; f++) {
				if ((1 << f) & now.p) continue;
				if (xx == feed[f].x && yy == feed[f].y) {
					flag = true;
					Q.push(Duck({ xx,yy }, (1 << f) | now.p,now.penal+ penalty[0], now.cnt + 1));
					break;
				}
			}
			if (!flag && ck[yy][xx][now.p]>now.penal+penalty[0] )
				Q.push(Duck({ xx,yy }, now.p, now.penal + penalty[0],now.cnt));
		}

		// Bishop
		for (int z = 0; z < 4; z++) {
			for (int k = 0;; k++) {
				int xx = now.pos.x + bishop_x[z] * k,yy = now.pos.y + bishop_y[z]*k;
				if (xx < 0 || yy < 0 || xx >= n || yy >= n) break;
				bool flag = false;
				for (int f = 0; f < m; f++) {
					if ((1 << f) & now.p) continue;
					if (xx == feed[f].x && yy == feed[f].y) {
						flag = true;
						Q.push(Duck({ xx,yy }, (1 << f) | now.p, now.penal + penalty[1], now.cnt + 1));
						break;
					}
				}
				if (!flag && ck[yy][xx][now.p]>now.penal + penalty[1])
					Q.push(Duck({ xx,yy }, now.p, now.penal + penalty[1],now.cnt));
			}
		}


		// Rook
		for (int z = 0; z < 4; z++) {
			for (int k = 0;; k++) {
				int xx = now.pos.x + rook_x[z] * k, yy = now.pos.y + rook_y[z] * k;
				if (xx < 0 || yy < 0 || xx >= n || yy >= n) break;
				bool flag = false;
				for (int f = 0; f < m; f++) {
					if ((1 << f) & now.p) continue;
					if (xx == feed[f].x && yy == feed[f].y) {
						flag = true;
						Q.push(Duck({ xx,yy }, (1 << f) | now.p, now.penal + penalty[2],now.cnt+1));
						break;
					}
				}
				if (!flag && ck[yy][xx][now.p]>now.penal + penalty[2])
					Q.push(Duck({ xx,yy }, now.p, now.penal + penalty[2],now.cnt));
			}
		}
	}

	return 0;
}