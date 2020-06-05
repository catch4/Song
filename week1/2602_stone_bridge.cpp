/*
Catch study 1����
����_2602 ���ٸ� �ǳʱ�
https://www.acmicpc.net/problem/2602
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
int n,m;
std::string dst, str1, str2;
int ck1[100][20],ck2[100][20];
int dfs(const int& now,const int& step,bool flag)
{
	int cnt = 0;
	if (now == n) return 1; // ������ ���, 1 ����

	for (int i = step; i < m; i++)
	{
		if (flag) {
			if (dst[now] == str1[i]) {
				if (ck1[i][now] == -1) // üũ �ȵǾ� ���� �� üũ
					ck1[i][now] = dfs(now + 1, i + 1, 0);
				cnt += ck1[i][now];
			}
		}
		else
		{
			if (dst[now] == str2[i]) {
				if (ck2[i][now] == -1)
					ck2[i][now] = dfs(now + 1, i + 1, 1);
				cnt += ck2[i][now];
			}
		}
	}
	// ������ ����� �� return
	return cnt;
}

int main() {
	std::cin >> dst >> str1 >> str2;	
	n = dst.size();
	m = str1.size();
	memset(ck1, -1, sizeof(ck1)); // üũ ���� �ٸ��� -1�� ����
	memset(ck2, -1, sizeof(ck2));
	// �� �ٸ� ���� ī��Ʈ
	std::cout << dfs(0, 0, 0)+dfs(0, 0, 1) << std::endl;

	return 0;
}