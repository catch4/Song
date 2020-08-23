/*
Catch study 11����
����_������
https://www.acmicpc.net/problem/1043
*/
/*-----------------
Ǯ��
�ٸ� ������ �����ϰ� ������ �ƴ� ��������
�� �� ���� ������ ���� ī����

1. ���� �ƴ� ��� ����
2. ����� �� ��Ƽ üũ
3. 
-----------------*/

#include <iostream>
#include <vector>
int n, m,p_n,answer;
bool member[50][50]; // 2.
bool peo_ck[50],par_ck[50]; // 3. ���, ��Ƽ visited
std::vector<int> police; // 1. ���� �ƴ� ���

void dfs(const int& people) {
	for (int i = 0; i < m; i++)
	{
		if (par_ck[i]||!member[people][i]) continue;
		for (int p = 0; p < n; p++) {
			if (peo_ck[p]) continue;
			if (member[p][i])
			{
				peo_ck[p] = 1; // üũ ���� ���, ��Ƽ�� üũ
				dfs(p);
			}
		}
		par_ck[i] = 1;
	}
}

int main() {
	std::cin >> n >> m>>p_n;
	police.resize(p_n);
	answer = m; // �ʱⰪ = m
	for (int i = 0; i < p_n; i++) std::cin >> police[i]; // 1.
	for (int j = 0; j < m; j++) {
		int tmp; std::cin >> tmp;
		for (int i = 0; i < tmp; i++) {
			int tmp2; std::cin >> tmp2;
			member[tmp2 - 1][j] = 1;
		}
	}
	if (!p_n) std::cout << m;
	else {
		for (int i = 0; i < p_n; i++) {
			peo_ck[police[i]-1] = 1;
			dfs(police[i]-1);
		}
		for (int i = 0; i < m; i++)
			if (par_ck[i]) answer--; // ������ ���ϴ� ��Ƽ ����
		std::cout << answer;
	}
	
}