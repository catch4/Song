/*
Catch study 3����
����_14888 ������ �����ֱ�
https://www.acmicpc.net/problem/14888
*/
/*
�ܼ��ϰ� ���� Ž��
1. ù��° ���ڴ� ������ +�̴�.
2. �ο����� �����ڸ� ����ϸ� ���� ����� �� �ִ� �����ڸ� üũ�ؾ��Ѵ�.
3. �ּҰ�,�ִ밪 �ֽ�ȭ�Ѵ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2147000000
int oper[4],min_num=MAX,max_num=-MAX,n;
int ck[4];
void dfs(std::vector<int>& vec, const int& now, const int& sum);
void n_dfs(std::vector<int>& vec, const int& now, const int& sum,const int& op) {
	ck[op]++;
	if (op == 0)
		dfs(vec, now + 1, sum + vec[now]);
	else if (op == 1)
		dfs(vec, now + 1, sum - vec[now]);
	else if (op == 2)
		dfs(vec, now + 1, sum*vec[now]);
	else
		dfs(vec, now + 1, sum / vec[now]);
	ck[op]--;
}

void dfs(std::vector<int>& vec,const int& now,const int& sum) {
	if (now == n)
	{
		min_num = std::min(min_num, sum); // 3.
		max_num = std::max(max_num, sum);
	}
	else 
		for (int i = 0; i < 4; i++)
			if (oper[i] - ck[i]) n_dfs(vec, now, sum, i); // 2.
}

int main() {
	std::cin >> n;
	std::vector<int> vec(n);
	for (int i = 0; i < n; i++) std::cin >> vec[i];
	std::cin >> oper[0] >> oper[1] >> oper[2] >> oper[3];
	dfs(vec, 1, vec[0]); // 1.
	std::cout << max_num <<'\n'<< min_num;
}