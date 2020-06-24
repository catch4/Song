/*
Catch study 4����
����_15684 ��ٸ� ����
https://www.acmicpc.net/problem/15684
*/
/*
------------------
������ ������ ��Ģ
------------------
�� ���ο� �������� ¦�������� �Ѵ�.
����) ������ Ȧ���� �����ϴ�
3 7 9
1 1
2 2
3 1
4 1
5 1
6 2
8 2
���� 7 1�� ������ �ǹǷ� 1

---------
Ʋ�� ����
---------
1. ���Ʈ���� ���� ������� ��Ģ�����ϸ鼭
   ¥�ôµ� �ð� 2�ð� �����ɸ��� Ʋ��
   ������ ���Ʈ ������ �ϴϱ� 30�е� �Ȱɸ� ȭ��

2. ��ó������ dsf(vecs ladder)�� ��������,
   sync,tie ���� ���� -> 
   dfs(vec& ladder)�� ��������, sync,tie �߰�
   �ؼ� �ð��ʰ� �����

3. �ٺ����� dfs���� for(int i=now+1)�� �����߾���


----
Ǯ��
----
���Ʈ������ ��, dfs ������ �ߺ� ���ϴ� �� ���ַ� �Ű���.

1-1. dfs������ 1�� ��ٸ�-> 2�� ��ٸ���
	 2�� ��ٸ�-> 1�� ��ٸ��� �ߺ��Ǳ� ������
	 ���������� ���� ���⸸ ��.

1-2. �ߺ��� ���ϱ� ���� n*h�� 1�������� �����ϰ�
	 i/n, i%n���� y,x�� ã�Ҵµ� 1-1�� ������ ���� ��������
	 ���ʿ� ��� x==n-1�� �� continue

*/

#include <iostream>
#include <vector>
#include <stack>
#define vecs std::vector<std::vector<int>>
int n, m, h;
bool possible(vecs& ladder) {
	for (int i = 0; i < n; i++)
	{
		int num = i;
		for (int j = 0; j < h; j++)
		{
			if (!ladder[j][num]) continue;
			num += ladder[j][num];
		}
		if (num != i) return false;
	}
	return true;
}

bool dfs(vecs& ladder, const int& dst, const int& choiced, const int& now) {
	if (choiced == dst)
	{
		if (possible(ladder)) return true;
	}
	else
	{
		for (int i = now; i < n*h; i++)
		{
			int y = i / n, x = i%n;
			if (x == n - 1) continue; // 1-2.
			if (ladder[y][x]||ladder[y][x+1]) continue;
			else
			{
				ladder[y][x] = 1; // 1-1.
				ladder[y][x + 1] = -1; // 1-1.
				if(dfs(ladder, dst, choiced + 1, i+1)) return true;
				ladder[y][x] = 0;
				ladder[y][x + 1] = 0;
			}
		}
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> m >> h;
	vecs ladder(h, std::vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		int y, x; std::cin >> y >> x;
		ladder[y - 1][x - 1] = 1;
		ladder[y - 1][x] = -1;
	}
	for (int i = 0; i <= 3; i++)
	{
		if (dfs(ladder,i,0,0))
		{
			std::cout << i << '\n';
			return 0;
		}
	}
	std::cout << -1 << '\n';
	return 0;
}

