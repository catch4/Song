/*
Catch study 13����
����_17825 �ֻ��� ������
https://www.acmicpc.net/problem/17825
*/
/*-----------------
Ʋ�ȴ� ����
- 25 �ߺ� üũ ����
- 40 �ߺ� üũ ����
- �迭�� �Ʒ�ó�� �������� 25,30,35,40 �ϴ� �ߺ� üũ�ؾ� �ϴµ� ����

Ǯ��
- �ߺ��� üũ�� �Ű澲�� �������� ���Ʈ ������ �����Ѵ�.
-----------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#define pi std::pair<int,int>
int dice[10],answer;
std::vector<int> map[5];

void dfs(std::vector<pi> pos, const int& used, const int& sum);
void init() { // ���� �ʱ�ȭ
	map[0].resize(21);
	map[1].resize(8);
	map[2].resize(7);
	map[3].resize(8);
	for (int i = 1; i < 21; i++)
		map[0][i] = i * 2;
	map[1] = { 10,13,16,19,25,30,35,40 };
	map[2] = { 20,22,24,25,30,35,40 };
	map[3] = { 30,28,27,26,25,30,35,40 };
}

void move(std::vector<pi> pos, const int& k, const int& used, const int& sum, const int& num) {
	int i = pos[k].first, j = pos[k].second;
	if (j + num >= map[i].size()) { // �����ϴ� ���
		pos[k].first = -1;
		dfs(pos, used + 1, sum);
	}
	else if (!i&&map[i][j + num] < 40 && map[i][j + num] % 10 == 0) { // ��ó�� �迭���� �ٸ� �迭�� �Ѿ�� �ϴ� ���
		for (int z = 0; z < 4; z++)
			if (pos[z].first == map[i][j + num] / 10 && !pos[z].second) return;
		pos[k].first = map[i][j + num] / 10;
		pos[k].second = 0;
		dfs(pos, used + 1, sum + map[i][j + num]);
	}
	else { // ������ ���
		for (int z = 0; z < 4; z++) { 
			if (pos[z].first == i && pos[z].second == j + num) return; // ���� �迭 ��ġ�� ���
			else if (j + num == map[i].size() - 1 && pos[z].second == map[pos[z].first].size() - 1) return; // 40 ��ġ�� ���
			else if (i>=1&&pos[z].first>=1 && j+num>=3&&pos[z].second>=3&& map[i][j + num]==map[pos[z].first][pos[z].second]) return; // 1,2,3 ��° �迭�� 25���� �ϴ� �ߺ�üũ
		}
		pos[k].first = i;
		pos[k].second = j + num;
		dfs(pos, used + 1, sum + map[i][j + num]);
	}
}

void dfs(std::vector<pi> pos,const int& used, const int& sum) {
	answer = std::max(answer, sum);
	if (used == 10) // �ֻ��� 10�� �پ�
		return;
	else {
		for(int k=0;k<4;k++)
			if(pos[k].first!=-1) // first�� -1�� ���� �̹� ������ ��
				move(pos, k, used, sum, dice[used]);
	}
}

int main() {
	std::vector<pi> pos(4, { 0,0 });
	for (int i = 0; i < 10; i++) std::cin >> dice[i];
	init();
	dfs(pos, 0, 0);
	std::cout << answer << '\n';
	return 0;
}