/*
Catch study 1����
����_1107 ������
https://www.acmicpc.net/problem/1107
*/

#include <iostream>
#include <vector>
int dst;
bool brk_bt[10];
int min = 2147000000;

void search(std::vector<int>& vec, int now, int& cnt)
{
	if (now == vec.size())
	{
		int sum = 0, cur = 1, limit = vec.size() - cnt;

		// ���ڹ�ư ������
		for (int i = now - 1; i >= limit; i--)
		{
			sum += cur*vec[i];
			cur *= 10;
		}
		// sum-dst�� +�� - ��������, cnt�� ���� ��ư ���� ����
		int result = abs(sum - dst) + cnt;
		if (result < min) min = result;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			// �� ���峭 ���ڹ�ư
			if (!brk_bt[i])
			{
				vec[now] = i;
				search(vec, now + 1, cnt);
				vec[now] = 0;
			}
		}
	}
}

int main() {
	int n, tmp; std::cin >> dst >> n;
	int simple = abs(100 - dst), cnt = 1,cnt_limit; // simple = +�� -�θ� ���� ���
	for (int i = 0; i < n; i++) { // ���峭 ��ư �Է�
		std::cin >> tmp;
		brk_bt[tmp] = 1;
	}
	// dst���� �ڸ��� �ϳ� �� ū�ź��� �ϳ� �� �����ű��� Ȯ��
	for (int i = 1; dst / i > 0; i *= 10) cnt++; 
	cnt_limit = (cnt - 3) >= 0 ? cnt-3 : 0; 
	
	std::vector<int> vec(cnt);
	for (int i = 0; cnt >cnt_limit; i++)
	{
		search(vec, i, cnt);
		cnt--;
	}
	if (min < simple) std::cout << min;
	else std::cout << simple;
	return 0;
}