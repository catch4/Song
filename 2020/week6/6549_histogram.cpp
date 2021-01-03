/*
Catch study 6����
����_6549 ������׷����� ���� ū ���簢��
https://www.acmicpc.net/problem/6549
*/
/*

Ʋ�ȴ� ����
1. ť�� �����غôµ� �Ź� ��� ���̿� ���� ���� +1 �ؼ� �ð��ʰ�
2. (7 1 3 7 10 5 4 1)���� 16 ���;� �ϴ� �� ������ index ������ؼ� 15 ����.
3. (7 1 1 7 10 5 4 1) ó�� �ߺ��Ǵ� ��� stack�� �ȳ־ index ��� �߸���.
	�ߺ��� �ִ� ������� �ٲ�

Ǯ��
�������� ����

0. ����, �� ���̷� ������� ���簢�� ��������, index ��ȣ

1. ������ ���� ���� �Էº��� ū ��� �� ���ڷ� �簢�� �� ������.
   ũ�� ���.

2. �Է¹��� ���ڰ� ������ ù ���ں��� ū���
   ���� index Ȯ�� ���ص� ��

3. �Է¹��� ���ڰ� ������ ù ���ں��� �۰ų� ���� ���
   �� ������ ���� �� ���� ���ں��� �����Ƿ� index+1���� ����
   ������ ��������� ���ÿ� ���ڰ� �־����� �� ������ں��� ũ�Ƿ� 0���� ����

4. stack�� ���� �� ���� ���� index���� ������ ���簢�� ���� �� ����.
   �̰� ���
*/
#include <iostream>
#include <algorithm>
#include <stack>
struct Block { // 0.
	int num = 0, start = 0, idx = 0;
	Block() {}
	Block(const int& n, const int& s, const int&i)
	{
		num = n; start = s; idx = i;
	}
};
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	while (1)
	{
		int n; std::cin >> n;
		if (!n) break;
		std::stack<Block> stk;
		long long max = 0;
		for (int i = 0; i < n; i++)
		{
			int num; std::cin >> num;
			if (stk.empty())
				stk.push(Block( num,i,i));
			else
			{
				Block temp = stk.top();
				while (!stk.empty()&&num < stk.top().num) // 1.
				{
					max = std::max(max, (long long)stk.top().num*(long long)(i - stk.top().start));
					stk.pop();
				}
				if(temp.num<num) stk.push(Block(num,i,i)); // 2.
				else if (temp.num >= num) {
					if(!stk.empty()) // 3.
						stk.push(Block(num, stk.top().idx + 1, i));
					else stk.push(Block(num, 0, i));
				}
			}
			
		}
		while (!stk.empty()) // 4.
		{
			max = std::max(max, (long long)stk.top().num*(long long)(n - stk.top().start));
			stk.pop();
		}
		std::cout << max << '\n';
	}
	return 0;
}
