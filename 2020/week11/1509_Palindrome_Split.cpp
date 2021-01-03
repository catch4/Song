/*
Catch study 11����
����_�Ӹ���� ����
https://www.acmicpc.net/problem/1509
*/
/*-----------------
Ǯ��
dfs + dp
���� ���������� �������� ����� �ִ� �Ӹ���� �� ����鼭
�� ���� ������ ����
-----------------*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
std::string str;
std::vector<int> vec;
int palin(const int& cur, int n_cur) {
	while (n_cur>1) {
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
	return 1;
}

int dfs(const int& cur) {
	if (cur == str.size()) {
		return 0;
	}
	else {
		if (vec[cur]) return vec[cur];
		else {
			int n_cur = str.size() - cur, ans = str.size();
			int ret = palin(cur, n_cur);
			while (ret > 1) {
				ans = std::min(dfs(cur + ret) + 1, ans);
				ret = palin(cur, ret - 1);
			}
			ans = std::min(dfs(cur + 1) + 1, ans);
			return vec[cur] = ans;
		}
	}
}
int main() {
	std::cin >> str;
	vec.resize(str.size(), 0);
	std::cout << dfs(0) << '\n';
}