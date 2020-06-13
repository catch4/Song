/*
Catch study 2����
����_16235 ��������ũ
https://www.acmicpc.net/problem/16235
*/

/*
Ǯ��

���� �˰����� ������� �ʰ� ���Ǵ�� ������.

Ʋ�ȴ� ����
- y�� x�� �߸� ����
- �� ó������ �� vector�� Tree ����ü�� �ְ� y,x,age ��� ���� �ɾ ������
  -> �ð��ʰ�
  -> vector�� [10][10](�ִ� ũ��)���� �����ϰ� �� vector �������� ����

0. 
	0-1. �������� ������ x,y�� ���� r,c�̸� r,c�� ���� ��,���� �ش���, ���� �Է� ���� �� y,x�� �޾ƾ���
	0-2. ����� cnt�� ��´�. ��ó�� m���� ������ �����Ƿ� m���� �Ҵ�.
	0-3. ���Ŀ��� ���ĵ� ������ ������ �״� ������ ������ ó���ϸ� �ȴ�.
	     ������ ���� 8���� �������� �ʱ� ������ push_back �� �� ī��Ʈ�Ѵ�.
	0-4. �߰��� ������ ������ 0�� �Ǹ� ���Ŀ��� ��� 0�̱� ������ �ݺ��� Ż��.
1. ��
	1-1. ���� ������ � ���̺��� ����� �Ծ�� �ϹǷ� �����ؾ���. ��ü y,x,age�� ���ϴ� �� ���� ��,���� �����Ҷ� age ���ϴ°� ������
	1-2. ���� �״� ������ ������ ������ �����Ѵ�.
	1-3. �״� ������ �����ϰ� ���� ����ִ� ������ �Ҵ��Ѵ�.
2. ����
	dead array�� age/2 ��ŭ ��� ���(���⼭�� vecs map)�� +
3. ����
	new_trees array�� ���� �迭�� ���� �� �϶� ���ο� ���� ����
4. �ܿ�
	ó�� �Ҵ���� A[r][c] �߰� (���⼭�� food)
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