/*
Catch study 11����
���α׷��ӽ�_���� �� �Ӹ����
https://programmers.co.kr/learn/courses/30/lessons/12904
*/
/*-----------------
Ǯ��
���� ������� �ִ밪���� ���� ��� �Լ����� ���´�.
-----------------*/
#include <iostream>
#include <string>
using namespace std;

int palin(string& str,const int& cur, int limit) {
	int n_cur = str.size() - cur;
	while (n_cur>limit) {
		bool flag = 1;
		for (int i = 0; i < (n_cur + 1) / 2; i++)
		{
			if (str[cur + i] != str[cur + n_cur - 1 - i])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			return n_cur;
		else
			n_cur -= 1;
	}
	return limit;
}
int solution(string s)
{
	int answer = 1;
	for (int i = 0; i < s.size(); i++)
		answer = palin(s, i, answer);
	return answer;
}

int main() {
	std::string s = "abcdcba";
	//std::string s = "abacde";
	std::cout << solution(s);
}