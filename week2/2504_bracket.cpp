/*
Catch study 2����
����_2504 ��ȣ�� ��
https://www.acmicpc.net/problem/2504
*/


/*
Ǯ��
�ؿ� (1.)�� (2.)�� ������ stack���� ����
�ִ� ���̴� 30�̹Ƿ� �ð��ʰ��� �Ű� ���� ����

Ʋ�ȴ� ����
- in_bracket�Լ����� �񱳸� == i �� �ϰ� �־���. 
- ���� ��ȣ�� ������ ��쿡 ���� ����ó�� ����.

1. ��ȣ�� �ùٸ��� �Ǵ�
   => ���� �ֱ� ���� ��ȣ �Ǵ�
   => ���Լ���
2. +�� x �Ǵ��ϱ� ���� ������ ǥ��, ���� cnt �����ؼ� ���
   => pair�� first = ��ȣ�� ��, second = ����(2 or 3) �ֱٰ��� ���� ū �ͳ����� �����ϸ��
   => ���Լ���
	2-1. ���ο� �ִ� ��ȣ ����
	2-2. ���ο� �ִ� ��ȣ ���� ����
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
	int cnt = 0; // 2. cnt�� ���� ǥ��
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