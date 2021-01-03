/*
Catch study 2����
����_2661 ���� ����
https://www.acmicpc.net/problem/2661
*/

/*
Ǯ��
����ϳ��� ������ �ǰ� �ִ� n�� 80�̶� dfs�� ����
1~3 ������� dfs�� Ž���ϰ� ����� ������ ������ 
�ּҰ��̱� ������ ���� ó�� X

0. ���� �迭 ��, �ִ� ũ��� ���� ������� �迭/2�� ��
1. ���� ������ �ϼ��ɶ��� ���� ũ���� �迭 Ž��
2. ����� �������� Ž�� Ż��
*/

#include <iostream>
#include <vector>
#include <string>
int n;
bool flag = 0;

bool good(std::string str) {
	int len = str.size() / 2;
	// 0.
	for (int i = 1; i <= len; i++)
	{
		int start1 = str.size() - i;
		int start2 = start1 - i;
		std::string str1 = "";
		std::string str2 = "";
		for (int j = start1;j< str.size(); j++)
			str1 += str[j];
		for (int j = start2; j < start1; j++)
			str2 += str[j];
		if (str1 == str2)
			return false;
	}
	// 0.
	return true;
}

void dfs(std::string str)
{
	if (str.size() == n) {
		std::cout << str;
		flag = 1; // 2.
	}
	else {
		for (int i = 1; i <= 3; i++)
		{
			// 1.
			if (good(str + char(i + '0')))
				dfs(str + char(i + '0'));
			// 1.
			if (flag) return; // 2.
		}
	}
}

int main() {
	std::cin >> n;
	dfs("");
	return 0;
}