/*
Catch study 6주차
백준_6549 히스토그램에서 가장 큰 직사각형
https://www.acmicpc.net/problem/6549
*/
/*

틀렸던 이유
1. 큐로 구현해봤는데 매번 모든 높이에 대해 길이 +1 해서 시간초과
2. (7 1 3 7 10 5 4 1)에서 16 나와야 하는 데 지나간 index 고려안해서 15 나옴.
3. (7 1 1 7 10 5 4 1) 처럼 중복되는 경우 stack에 안넣어서 index 계산 잘못됨.
	중복도 넣는 방식으로 바꿈

풀이
스텍으로 구현

0. 높이, 이 높이로 만들어진 직사각형 시작지점, index 번호

1. 스택의 수가 현재 입력보다 큰 경우 이 숫자로 사각형 더 못만듬.
   크기 계산.

2. 입력받은 숫자가 스택의 첫 숫자보다 큰경우
   앞의 index 확인 안해도 됨

3. 입력받은 숫자가 스택의 첫 숫자보다 작거나 같은 경우
   다 빼고나서 남은 게 현재 숫자보다 작으므로 index+1에서 시작
   스택이 비어있으면 스택에 숫자가 있었더라도 다 현재숫자보다 크므로 0부터 시작

4. stack의 남은 수 들은 시작 index에서 끝까지 직사각형 만들 수 있음.
   이거 계산
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
