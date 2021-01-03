/*
Catch study 11����
����_���ƽý� �����
https://www.acmicpc.net/problem/3015
*/
/*-----------------
Ǯ��
Ʋ��, ���ͳ� �ڵ� ���ظ���
-----------------*/
#include <iostream>
#include <stack>
#define pi std::pair<int,int>
int main()
{
	std::ios_base::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin >> n;
	std::stack<pi> s;

	long long result = 0;
	for (int i = 0; i < n; i++)
	{
		int height; std::cin >> height;
		while (!s.empty() && s.top().first < height)
		{
			result += s.top().second; // ���� ����� ������ ū�� �����ϸ� +�ѽ�
			s.pop();
		}

		if (s.empty())
			s.push({ height, 1 });
		else
		{
			if (s.top().first == height) // �ߺ��� �� ���� ó��
			{
				pi cur = s.top();
				s.pop();
				result += cur.second;
				if (!s.empty())
					result++;
				cur.second++;
				s.push(cur);
			}
			else
			{
				s.push({ height, 1 }); // ���� ���� �ѽ�
				result++;
			}
		}
	}
	std::cout << result << "\n";
	return 0;
}