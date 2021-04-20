/*
Catch study 14/apr/3week
백준_Maaaaaaaaaze
https://www.acmicpc.net/problem/16985
*/
/*-----------------
풀이
map을 매번 만들진 않고 회전 횟수와 선택된 layer를 기억하고 lookup 느낌으로 구현했습니다.
is_layer_duple 함수는 안쓰는게 더 빠르네요

-----------------*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define vec2d std::vector<std::vector<bool>>


bool choice_ck[5], move_ck[5][5][5]; // 선택 체크 배열 (dfs 함수에서 사용), 이동 체크 배열 (bfs 함수에서 사용) 
std::vector<int> layer_ck[5]; // is_layer_duple 함수에서 사용. 안쓰는게 더 빠름
int answer = 2147000000, dl[6] = { 1,-1,0,0,0,0 }, dx[6] = { 0,0,0,1,0,-1 }, dy[6] = { 0,0,1,0,-1,0 };

struct Maze {
	vec2d layer[5]; // layer 정보
	int idx[5],rot[5]; // 첫번째에 놓인 layer가 몇번째 layer인지, 첫번째가 몇번 시계방향으로 회전했는지
	
	void cin() {
		int num;
		for (int l = 0; l < 5; l++){
			layer[l].resize(5);
			for (int i = 0; i < 5; i++) {
				layer[l][i].resize(5);
				for (int j = 0; j < 5; j++) {
					std::cin >> num;
					layer[l][i][j] = num;
				}
			}
		}
	}
	bool is_move(const int& l, const int& y, const int& x) { // idx, rot 정보를 사용해 해당값 return
		if (rot[l] == 0)
			return layer[idx[l]][y][x];
		else if (rot[l] == 1)
			return layer[idx[l]][4 - x][y];
		else if (rot[l] == 2)
			return layer[idx[l]][4 - y][4 - x];
		else
			return layer[idx[l]][x][4 - y];
	}

	bool is_layer_duple() { // 선택된 5개의 조합이 이미 한적있나 체크하는 함수, 안쓰는게 더 빠름
		int num[5];
		for (int l = 0; l < 5; l++) {
			num[l] = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (is_move(l, i, j))
						num[l] = num[l] | (1 << (i * 5 + j));
				}
			}
		}

		for (int i = 0; i < layer_ck[0].size(); i++) {
			for (int l = 0; l < 5; l++) {
				if (layer_ck[l][i] != num[l]) break;
				if (layer_ck[l][i] == num[l] && l==4) return true;				
			}
		}

		for (int l = 0; l < 5; l++)
			layer_ck[l].push_back(num[l]);

		return false;
	}
};

struct Info {
	int l, y, x,c;
	Info() {}
	Info(const int& layer, const int& y_pos, const int& x_pos, const int& cnt) { l = layer, y = y_pos, x = x_pos,c=cnt; }

};


void bfs(Maze& maze) { // 단순 bfs
	memset(move_ck, 0, sizeof(move_ck));
	move_ck[0][0][0] = 1;
	std::queue<Info> Q;
	Q.push(Info(0, 0, 0, 0));
	while (!Q.empty()) {
		Info now = Q.front();
		Q.pop();

		for (int z = 0; z < 6; z++) {
			int nl = now.l + dl[z], ny = now.y + dy[z], nx = now.x + dx[z];
			if (nl < 0 || nl >= 5||ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || move_ck[nl][ny][nx] || !maze.is_move(nl, ny, nx)) continue;
			move_ck[nl][ny][nx] = 1;
			if (nl == 4 && ny == 4 && nx == 4) {
				answer = answer > now.c + 1 ? now.c + 1 : answer;
				return;
			}
			Q.push(Info(nl, ny, nx, now.c + 1));
		}
	}
}

void dfs(Maze& maze, const int& now) { // 어떤 mp를 now층에 놓을지 선택하고 5개가 다 놓이면 bfs실행
	if (now == 5) bfs(maze);
	else {
		for (int i = 0; i < 5; i++) {
			if (choice_ck[i]) continue;
			choice_ck[i] = 1;
			maze.idx[now]=i;
			for (int z = 0; z < 4; z++) {
				maze.rot[now] = z;
				if (now == 0 && !maze.is_move(now,0,0)) continue; // 스타트 지점이 0이어도 continue
				else if (now == 4 && (!maze.is_move(now, 4, 4) || maze.is_layer_duple())) continue; // 도착지점이 0이어도 continue, is_layer_duple은 없는게 빠름
				dfs(maze, now + 1);
			}
			choice_ck[i] = 0;
		}
	}
}

int main() {
	Maze maze;
	maze.cin();
	dfs(maze, 0);
	if (answer == 2147000000) std::cout << -1;
	else std::cout << answer;
	return 0;
}