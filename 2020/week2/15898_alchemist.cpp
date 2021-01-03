/*
Catch study 2����
����_15898 �Ǿ��� ��Ʋ���� ~�ź��� ��ȸ�� ���ݼ���~
https://www.acmicpc.net/problem/2504
*/

/*
Ǯ��
��� ������ Ž���ؾ��Ѵ�.
�ð� ���� 3�ʿ��� ȸ���ϴ� �κи� �ð����̴� ������� ����
�޸𸮴� ������ dfs���� �Ѱ��ִ� �κл���� �ּҷ� ���.

0. dfs�� 2���� ����
	0-1. n���� matrial�� 3���� �����Ѵ�. ������ ���� ����� �޶����Ƿ�
		 ��� ������ �����ؾ� �Ѵ�.
	0-2. ���յ� 3���� ���� �ݽð� ȸ�� Ƚ�� 4�� (0,1,2,3)=rot,
		 ������ ��ġ(=offset) 4�� ��� ������ �ؾ��Ѵ�.

1. ���
	1-1. color�� ������ �������� ���ڷ� ��ȯ�ؾ��ϹǷ� �Է� ������ ��ȯ.
	1-2. rot�� �ݽð� �������� ȸ���� Ƚ�� 0~3�� ��, ���� �������� �ʰ�
		 �ٷ� return

2. ����
	2-1. ������ ���ǿ� �°� material�� �����Ѵ�.
		 ���� dfs�� �Ѱ��ְ� ���� ���� �ٸ� ������
		 ����ؾ� �ϹǷ� ���ο� ����ü�� return �Ѵ�.
		 (�� �κ��� �޸������� 512MB���� ���� �����Ŷ�� ������)
	2-2. 3���� matrial�� ��� ����� ��� ��ź�� �����Ѵ�.

3. ���� ������� ��ź�� ���� ������ ���� ��ź�� �����Ѵ�.
*/

#include <iostream>
#include <vector>

// 1.
struct Mater {
	int qual[4][4];
	int color[4][4];
	// 1-1.
	void cin_color(const int& i, const int& j)
	{
		char temp;
		std::cin >> temp;
		if (temp == 'R') color[i][j] = 7;
		else if (temp == 'B') color[i][j] = 5;
		else if (temp == 'G') color[i][j] = 3;
		else if (temp == 'Y') color[i][j] = 2;
		else color[i][j] = 0;
	}
	// 1-1.

	// 1-2.
	int rotation_qual(const int& i, const int& j, const int& rot)
	{
		if (rot == 0) return qual[i][j];
		else if (rot == 1)
			return qual[j][3 - i];
		else if (rot == 2)
			return qual[3 - i][3 - j];
		else
			return qual[3 - j][i];
	}
	int rotation_color(const int& i, const int& j, const int& rot)
	{
		if (rot == 0) return color[i][j];
		else if (rot == 1)
			return color[j][3 - i];
		else if (rot == 2)
			return color[3 - i][3 - j];
		else
			return color[3 - j][i];
	}
	// 1-2.
};

int dy[4] = { 0,0,1,1 };
int dx[4] = { 0,1,0,1 };

struct Kiln {
	int kiln_qual[5][5] = { 0, };
	int kiln_color[5][5] = { 0, };
	int bomb = 0;

	// 2-2.
	int make_bomb() {
		if (!bomb) {
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					bomb += kiln_qual[i][j] * kiln_color[i][j];
		}
		return bomb;
	}
	// 2-2.

	// 2-1.
	Kiln apply_mater(Mater& mat,const int& rot,const int& offset) {
		Kiln ret;
		for(int i=0;i<5;i++)
			for (int j = 0; j < 5; j++) {
				ret.kiln_color[i][j] = kiln_color[i][j];
				ret.kiln_qual[i][j] = kiln_qual[i][j];
			}

		for(int i=dy[offset];i<dy[offset]+4;i++)
			for (int j = dx[offset]; j < dx[offset] + 4; j++)
			{
				ret.kiln_qual[i][j] += mat.rotation_qual(i - dy[offset], j - dx[offset], rot);
				if (ret.kiln_qual[i][j] < 0) ret.kiln_qual[i][j] = 0;
				else if (ret.kiln_qual[i][j] > 9) ret.kiln_qual[i][j] = 9;
				
				if (mat.rotation_color(i - dy[offset], j - dx[offset], rot))
					ret.kiln_color[i][j] = mat.rotation_color(i - dy[offset], j - dx[offset], rot);
			}
		return ret;
	}
	// 2-1.

};

#define M_vec std::vector<Mater>

bool ck[10] = { 0, };
int max = 0;
M_vec choice(3);
int n;

// 0-2.
void apply(const int& now,Kiln kiln) {
	if (now == 3)
	{
		int bomb = kiln.make_bomb();
		if (max < bomb) max = bomb; // 3.
	}
	else
	{
		for (int rot = 0; rot < 4; rot++)
		{
			for (int offset = 0; offset < 4; offset++)
				apply(now + 1, kiln.apply_mater(choice[now], rot, offset));
		}
	}
}
// 0-2.

// 0-1.
void dfs(const int& now, M_vec& matrials) {
	if (now == 3)
	{
		Kiln temp;
		apply(0,temp);
	}
	else
	{
		for(int i=0;i<n;i++)
			if (!ck[i])
			{
				ck[i] = 1;
				choice[now] = matrials[i];
				dfs(now+1, matrials);
				ck[i] = 0;
			}
	}
}
// 0-1.

int main() {
	std::cin >> n;
	M_vec materials(n);
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				std::cin >> materials[k].qual[i][j];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				materials[k].cin_color(i,j); // 1-1.
	}
	dfs(0, materials);
	std::cout << max << std::endl;
	return 0;
}