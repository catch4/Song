/*
Catch study 4����
����_16637 ��ȣ �߰��ϱ�
https://www.acmicpc.net/problem/16637
*/

/*
���Ʈ ������ ����
buscket �Լ� �κ��� �ð� �ʰ� �� �� �˾Ҵµ� �ȳ�

1. ��ȣ�� �ִ� ������ int(n/2), 0~�ִ밳�� ���� ���ռ���
2. �ϼ��� ���� ������� ��� 
3. ��ȣ ��� �ϰ� �ٲ� ���� �ݿ�
4. ������, �� �� ���� ����ؼ� ���
*/

#include<iostream>
#include<vector>

int max = -2147000000;
struct Equation {
	std::vector<int> oper;
	std::vector<int> num;
	Equation(const int& size) {
		oper.resize(size - 1);
		num.resize(size);
	}
};

int cal_oper(const int& a, const int&b, const int& oper) //4.
{
	if (oper == 1) return a + b;
	else if (oper == 2) return a - b;
	else return a*b;
}

int cal(Equation& eq) // 2.
{
	int ret = eq.num[0];
	for (int i = 0; i < eq.oper.size(); i++)
		ret = cal_oper(ret, eq.num[i + 1], eq.oper[i]); // 4.
	return ret;
}

Equation buscket(Equation& eq,const int& pos) // 3.
{
	Equation ret(eq.oper.size());
	for (int i = 0; i < pos; i++)
	{
		ret.oper[i] = eq.oper[i];
		ret.num[i] = eq.num[i];
	}
	ret.num[pos] = cal_oper(eq.num[pos], eq.num[pos + 1], eq.oper[pos]);
	for (int i = pos + 1; i < eq.oper.size(); i++)
	{
		ret.oper[i - 1] = eq.oper[i];
		ret.num[i] = eq.num[i + 1];
	}
	return ret;
}

void dfs(Equation eq, 
	const int& dst,const int& choiced,const int& pos) {
	if (dst == choiced)
	{
		int ret = cal(eq); // 2.
		if (ret > max) max = ret;
	}
	else
		for (int i = pos; i < eq.oper.size(); i++)
			dfs(buscket(eq,i), dst, choiced + 1, i + 1); // 3.
}

int main() {
	int n; std::cin >> n;
	char tmp;
	Equation eq(n / 2+1);

	for (int i = 0; i < n; i++) {
		std::cin >> tmp;
		if (i % 2==0)
			eq.num[i / 2] = tmp - '0';
		else
		{
			if (tmp == '+') eq.oper[i / 2] = 1;
			else if (tmp == '-') eq.oper[i / 2] = 2;
			else if (tmp == '*') eq.oper[i / 2] = 3;
		}
	}
	for (int i = 0; i <= n / 2; i++)  // 1.
		dfs(eq, i, 0, 0);
	std::cout << max << std::endl;
	return 0;
}