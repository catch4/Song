/*
Catch study 11주차
백준_오아시스 재결합
https://www.acmicpc.net/problem/3015
*/
/*-----------------
풀이
틀림, 인터넷 코드 이해만함
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
			result += s.top().second; // 현재 저장된 값보다 큰게 존재하면 +한쌍
			s.pop();
		}

		if (s.empty())
			s.push({ height, 1 });
		else
		{
			if (s.top().first == height) // 중복일 때 따로 처리
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
				s.push({ height, 1 }); // 이전 값과 한쌍
				result++;
			}
		}
	}
	std::cout << result << "\n";
	return 0;
}