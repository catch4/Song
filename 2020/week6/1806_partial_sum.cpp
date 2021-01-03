/*
Catch study 6����
����_1806 �κ���
https://www.acmicpc.net/problem/1806
*/
/*
������ Ǯ���� �Ŷ� �ѹ��� ����� �� �˾Ҵµ�
�߰��� for�� �߸������ؼ� ������ Ʋ�ȴ�.
�����յ� long long���� ���߾���.

Ʋ�ȴ� ���� - for�� ���� ������ idx���� �߾�� �ߴ�.

�������ͷ� ����
1. �迭�� �Է� ���� �� ���������� �޴´�.
2. �������� s���� ���� idx ������ �� �ʿ� ��� ������ ����
3. ������ �������� s���� ���� ��� 0 ��ȯ
4. �迭�� ���̰� �ּ�ȭ �ɶ����� �����ϰ� ���� index ���ʹ�
   �ֽ�ȭ �� �迭�� ���� ���� Ȯ���غ���.
*/

#include <iostream>
#include <vector>
int n, s,idx;

int Find_sum(std::vector<long long>& sums) {
	int min = idx;
	for (int cur = idx; cur < n + 1; cur++)
	{
		for (int j = cur - min; j < cur; j++) // 4.
			if (sums[cur] - sums[j] >= s) min = cur - j;
			else break;
	}
	return min;
}

int main() {
	std::cin >> n >> s;
	idx = n;
	std::vector<long long> sums(n + 1);
	for (int i = 1; i < n + 1; i++) {
		int num; std::cin >> num;
		sums[i] = (long long)num + sums[i - 1]; // 1.
		if (sums[i] >= s && idx > i) idx=i; // 2.
	}
	if (sums[n] < s) std::cout << 0 << '\n'; // 3.
	else std::cout << Find_sum(sums) << '\n'; // 4.
	
	return 0;	
}