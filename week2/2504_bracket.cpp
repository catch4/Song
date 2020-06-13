/*
Catch study 2주차
백준_2504 괄호의 값
https://www.acmicpc.net/problem/2504
*/


/*
풀이
밑에 (1.)과 (2.)의 이유로 stack으로 구현
최대 길이는 30이므로 시간초과는 신경 쓰지 않음

틀렸던 이유
- in_bracket함수에서 비교를 == i 로 하고 있었음. 
- 여는 괄호로 끝나는 경우에 대한 예외처리 안함.

1. 괄호가 올바른지 판단
   => 가장 최근 여는 괄호 판단
   => 후입선출
2. +와 x 판단하기 위해 층으로 표시, 층은 cnt 선언해서 계산
   => pair의 first = 괄호의 층, second = 점수(2 or 3) 최근값중 층이 큰 것끼리만 덧셈하면됨
   => 후입선출
	2-1. 내부에 있는 괄호 덧셈
	2-2. 내부에 있는 괄호 값과 곱셈
*/

#include <iostream>
#include <stack>
#include <string>

#define pstk std::stack<std::pair<int,int>>

// 2-1.
int in_bracket(pstk& brackets,int i) {
	int num = 0;
	while (!brackets.empty())
	{
		if (brackets.top().first <= i)
			break;
		num += brackets.top().second;
		brackets.pop();
	}
	return num;
}
// 2-1.

int main() {
	
	std::string str; std::cin >> str;
	
	// 1.
	std::stack<char> stk;
	
	pstk brackets;
	int cnt = 0; // 2. cnt로 층수 표현
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ')')
		{
			if (stk.empty() || stk.top() != '(') // 1.
			{
				std::cout << 0;
				return 0;
			}
			else
			{
				stk.pop();
				if (brackets.empty()||brackets.top().first<=cnt)
					brackets.push({ cnt,2 });
				else if (brackets.top().first > cnt) 
					brackets.push({ cnt,2 * in_bracket(brackets,cnt) }); // 2-2. , 2-1
			}
			cnt--;
		}
		else if (str[i] == ']')
		{
			if (stk.empty() || stk.top() != '[') // 1.
			{
				std::cout << 0;
				return 0;
			}
			else
			{
				stk.pop();
				if (brackets.empty() || brackets.top().first <= cnt)
					brackets.push({ cnt,3 });
				else if (brackets.top().first > cnt) 
					brackets.push({ cnt,3 * in_bracket(brackets,cnt) }); // 2-2. , 2-1
			}
			cnt--;
		}
		else {
			if (str[i] != '('&&str[i] != '[')
			{
				std::cout << 0;
				return 0;
			}
			stk.push(str[i]);
			cnt++;
		}
	}
	if (!stk.empty())
		std::cout << 0;
	else
		std::cout << in_bracket(brackets, 0);
	return 0;
}