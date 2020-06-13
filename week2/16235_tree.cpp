/*
Catch study 2주차
백준_16235 나무재테크
https://www.acmicpc.net/problem/16235
*/

/*
풀이

딱히 알고리즘을 사용하진 않고 조건대로 구현함.

틀렸던 이유
- y와 x를 잘못 받음
- 맨 처음에는 한 vector에 Tree 구조체를 넣고 y,x,age 모두 조건 걸어서 정렬함
  -> 시간초과
  -> vector를 [10][10](최대 크기)으로 선언하고 한 vector 내에서만 정렬

0. 
	0-1. 문제에서 나오는 x,y는 각각 r,c이며 r,c가 각각 행,열에 해당함, 따라서 입력 받을 때 y,x로 받아야함
	0-2. 결과는 cnt에 담는다. 맨처음 m개의 나무가 있으므로 m으로 할당.
	0-3. 이후에는 번식된 나무의 개수와 죽는 나무의 개수만 처리하면 된다.
	     번식할 때는 8개로 고정되지 않기 때문에 push_back 할 때 카운트한다.
	0-4. 중간에 나무의 개수가 0이 되면 이후에도 계속 0이기 때문에 반복문 탈출.
1. 봄
	1-1. 봄이 오기전 어린 나이부터 양분을 먹어야 하므로 정렬해야함. 전체 y,x,age를 비교하는 것 보다 행,열이 동일할때 age 비교하는게 더빠름
	1-2. 봄에 죽는 나무와 번식할 나무를 저장한다.
	1-3. 죽는 나무를 제외하고 현재 살아있는 나무를 할당한다.
2. 여름
	dead array의 age/2 만큼 양분 행렬(여기서는 vecs map)에 +
3. 가을
	new_trees array의 인접 배열이 범위 내 일때 새로운 나무 생성
4. 겨울
	처음 할당받은 A[r][c] 추가 (여기서는 food)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define vecs std::vector<std::vector<int>>
struct Tree {
	int y, x, age;
	Tree(const int& t_x, const int& t_y, const int& t_age)
	{
		y = t_y; x = t_x; age = t_age;
	}
};
int n, m, k,cnt;
std::vector<int> trees[10][10];
std::vector<Tree> dead;
std::vector<Tree> new_trees;
int dy[8] = { -1,-1,-1,0,1,1,1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };

void spring(vecs& map) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			int size = trees[i][j].size();
			if (size) {
				std::vector<int> tree_tmp;
				//1-2.
				for (int z = 0; z < size; z++)
				{
					if (map[i][j] >= trees[i][j][z])
					{
						map[i][j] -= trees[i][j][z];
						tree_tmp.push_back(trees[i][j][z] + 1);
						if ((trees[i][j][z]+1)%5==0) new_trees.push_back(Tree(j, i, trees[i][j][z] + 1));
					}
					else
						dead.push_back(Tree(j, i, trees[i][j][z]));
				}
				//1-2.

				//1-3.
				trees[i][j] = tree_tmp;
				//1-3.
			}
		}
	}
}
// 2.
void summer(vecs& map) {
	
	for (int i = 0; i < dead.size(); i++)
		map[dead[i].y][dead[i].x]+=dead[i].age/2;
	// 0-3.
	cnt -= int(dead.size());
}
// 2.

// 3.
void fall() {
	for (int i = 0; i < new_trees.size(); i++) {
		int y = new_trees[i].y;
		int x = new_trees[i].x;
		for (int k = 0; k < 8; k++)
		{
			int n_y = y + dy[k];
			int n_x = x + dx[k];
			if (n_y >= 0 && n_y < n&&n_x >= 0 && n_x < n) {
				trees[n_y][n_x].push_back(1);
				// 0-3.
				cnt++;
			}
		}
	}
}
// 3.

// 4.
void winter(vecs& map, vecs& food) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			map[i][j] += food[i][j];
}
// 4.

void init() {
	// 1_1.
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sort(trees[i][j].begin(), trees[i][j].end());
	// 1_1.
	dead.clear();
	new_trees.clear();
}

int main() {
	std::cin >> n >> m >> k;
	// 0-2.
	cnt = m;

	vecs map(n, std::vector<int>(n, 5));
	vecs food(n, std::vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> food[i][j];

	// 0-1.
	for (int i = 0; i < m; i++)
	{
		int x, y, age;
		std::cin >> y >> x >> age;
		trees[y - 1][x - 1].push_back(age);
	}
	// 0-1.

	for (int t = 0; t < k; t++)
	{
		init();
		spring(map);
		summer(map);
		fall();
		winter(map, food);

		// 0-4.
		if (!cnt) break;
		// 0-4.
	}
	std::cout << cnt << std::endl;
	return 0;
}