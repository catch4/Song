/*
Catch study 14/apr/3week
����_Maaaaaaaaaze
https://www.acmicpc.net/problem/16985
*/
/*-----------------
Ǯ��
map�� �Ź� ������ �ʰ� ȸ�� Ƚ���� ���õ� layer�� ����ϰ� lookup �������� �����߽��ϴ�.
is_layer_duple �Լ��� �Ⱦ��°� �� �����׿�

-----------------*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define vec2d std::vector<std::vector<bool>>


bool choice_ck[5], move_ck[5][5][5]; // ���� üũ �迭 (dfs �Լ����� ���), �̵� üũ �迭 (bfs �Լ����� ���) 
std::vector<int> layer_ck[5]; // is_layer_duple �Լ����� ���. �Ⱦ��°� �� ����
int answer = 2147000000, dl[6] = { 1,-1,0,0,0,0 }, dx[6] = { 0,0,0,1,0,-1 }, dy[6] = { 0,0,1,0,-1,0 };

struct Maze {
	vec2d layer[5]; // layer ����
	int idx[5],rot[5]; // ù��°�� ���� layer�� ���° layer����, ù��°�� ��� �ð�������� ȸ���ߴ���
	
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
	bool is_move(const int& l, const int& y, const int& x) { // idx, rot ������ ����� �ش簪 return
		if (rot[l] == 0)
			return layer[idx[l]][y][x];
		else if (rot[l] == 1)
			return layer[idx[l]][4 - x][y];
		else if (rot[l] == 2)
			return layer[idx[l]][4 - y][4 - x];
		else
			return layer[idx[l]][x][4 - y];
	}

	bool is_layer_duple() { // ���õ� 5���� ������ �̹� �����ֳ� üũ�ϴ� �Լ�, �Ⱦ��°� �� ����
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


void bfs(Maze& maze) { // �ܼ� bfs
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

void dfs(Maze& maze, const int& now) { // � mp�� now���� ������ �����ϰ� 5���� �� ���̸� bfs����
	if (now == 5) bfs(maze);
	else {
		for (int i = 0; i < 5; i++) {
			if (choice_ck[i]) continue;
			choice_ck[i] = 1;
			maze.idx[now]=i;
			for (int z = 0; z < 4; z++) {
				maze.rot[now] = z;
				if (now == 0 && !maze.is_move(now,0,0)) continue; // ��ŸƮ ������ 0�̾ continue
				else if (now == 4 && (!maze.is_move(now, 4, 4) || maze.is_layer_duple())) continue; // ���������� 0�̾ continue, is_layer_duple�� ���°� ����
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