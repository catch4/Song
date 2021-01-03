/*
Catch study 21/jan/1week
����_����
https://www.acmicpc.net/problem/2234
*/
/*-----------------
Ǯ��
dfs�� Ǯ��
1. �̵� ������ ��� ������ ��. �� size �ֽ�ȭ, �� max size �ֽ�ȭ
2. �̵� �Ұ����ϰ� ������ ���� �̹� �湮�� ���̸� �̿����� ����
3. �̿������� ���� ����� �ִ� �ִ밪

����
rooms = �� ����(0���� �����ؼ� ���߿� print�Ҷ��� +1)
merge_room = �̿��� ������ �ִ밪
max_room = size�� ���� ū room�� size
neighbor = �̿� ����, dense matrix
-----------------*/
#include <iostream>
#include <vector>
#define vec2d(type) std::vector<std::vector<type>>

int n,m,rooms = -1,max_room=0,merge_room=0, dy[4] = { 1, 0, -1, 0 }, dx[4] = { 0,1,0,-1 }, wall[4] = { 8, 4, 2, 1};
std::vector<int> room_size;
vec2d(bool) neighbor;


void find_room(vec2d(int)& mp, vec2d(int)& room,const int& i,const int& j) {
	room[i][j] = rooms;
	room_size[rooms] += 1;
	if (room_size[rooms] > max_room)
		max_room = room_size[rooms];
	int info = mp[i][j];
	for (int z = 0; z < 4; z++) {
		int y = i + dy[z], x = j + dx[z];
		if (x < 0 || x >= n || y < 0 || y >= m) {
			info -= wall[z];
			continue;
		}
		if (info<wall[z]) {	
			if (room[y][x] == -1)
				find_room(mp, room, y, x);
		}
		else {
			info -= wall[z];
			if (room[y][x] != -1) {
				neighbor[rooms][room[y][x]] = 1;
				neighbor[room[y][x]][rooms] = 1;
			}
		}
	}
}

int main() {
	std::cin >> n >> m;
	vec2d(int) mp(m, std::vector<int>(n));
	vec2d(int) room(m, std::vector<int>(n, -1));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			std::cin >> mp[i][j];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (room[i][j]!=-1) continue;
			rooms += 1;
			room_size.push_back(0);
			neighbor.push_back(std::vector<bool>(rooms+1));
			for (int z = 0; z < rooms; z++)
				neighbor[z].push_back(0);
			find_room(mp, room, i, j);
		}

	merge_room = max_room;
	for (int i = 0; i < rooms + 1; i++)
		for (int j = i + 1; j < rooms + 1; j++)
			if (neighbor[i][j] && merge_room < room_size[i] + room_size[j])
				merge_room = room_size[i] + room_size[j];


	std::cout << rooms + 1 << '\n' << max_room << '\n' << merge_room << '\n';
}