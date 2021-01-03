/*
Catch study 2����
����_2352 �ݵ�ü ����
https://www.acmicpc.net/problem/2352
*/

/*
Ǯ��
�ִ� �迭���̰� 40000�̰�, �ð����� 2�ʶ� O(n)�� ������ �����Ϸ��� ��.
=> ���̳��� ���α׷���
���� ����� ������ index�� �ϰ� �� index�� �ּ� ���ڸ� �Ҵ�.
index�� ���� ���� O(n)�� �����, index�� ũ���� ���� ������
�ٷ� Ż���ϱ� ������ O(n2)���� ����

0. ����Ƚ�� = index, index�� = �ּ� ���� �� �����ϴ� �迭 ����(chain)
1. chain�� index�� ū �� ���� ��
	1-1. ���� ���ڰ� chain�� �ִ� index���� Ŭ ���� push_back
	1-2. ���� ���ڰ� chain�� ���� index���� Ŭ ��� index+1 ��ġ��
	     ���� ���� �ּҰ� �Ҵ�
2. chain�� ù index�� 0�̱� ������ -1

*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n; std::cin >> n;
	int max_idx = 0;
	std::vector<int> nums(n);
	for (int i = 0; i < n; i++)
		std::cin >> nums[i];
	std::vector<int> chain; // 0.
	chain.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int len = chain.size();
		for(int j=len-1;j>=0;j--)
			if (chain[j] < nums[i])
			{
				if (j == len - 1)
					chain.push_back(nums[i]); // 1-1.
				else
					chain[j + 1] = std::min(chain[j + 1], nums[i]); // 1-2.
				break;
			}
	}
	
	std::cout << chain.size() - 1 << std::endl; // 2.
}