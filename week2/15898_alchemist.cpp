/*
Catch study 2주차
백준_15898 피아의 아틀리에 ~신비한 대회의 연금술사~
https://www.acmicpc.net/problem/2504
*/

/*
풀이
모든 조건을 탐색해야한다.
시간 제한 3초여서 회전하는 부분만 시간줄이는 방식으로 구현
메모리는 가마를 dfs에서 넘겨주는 부분빼고는 최소로 사용.

0. dfs는 2개로 구성
	0-1. n개의 matrial중 3개를 선택한다. 순서에 따라 결과가 달라지므로
		 모든 조합을 선택해야 한다.
	0-2. 조합된 3개의 재료는 반시계 회전 횟수 4개 (0,1,2,3)=rot,
		 적용할 위치(=offset) 4개 모든 조합을 해야한다.

1. 재료
	1-1. color는 어차피 마지막에 숫자로 변환해야하므로 입력 받을때 변환.
	1-2. rot는 반시계 방향으로 회전한 횟수 0~3의 값, 따로 저장하지 않고
		 바로 return

2. 가마
	2-1. 문제의 조건에 맞게 material을 적용한다.
		 다음 dfs로 넘겨주고 현재 값은 다른 조합을
		 계산해야 하므로 새로운 구조체를 return 한다.
		 (이 부분은 메모리제한이 512MB여서 문제 없을거라고 생각함)
	2-2. 3개의 matrial이 모두 적용된 경우 폭탄을 생성한다.

3. 현재 만들어진 폭탄중 가장 점수가 높은 폭탄을 저장한다.
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