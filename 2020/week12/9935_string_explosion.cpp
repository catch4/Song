/*
Catch study 12����
����_���ڿ� ����
https://www.acmicpc.net/problem/9935
*/
/*-----------------
Ǯ��
���� ���ڿ��� ������ ���ڿ� �����Ҷ��� Ȯ��
substr ����ؼ� ���Ҵ� �ϸ� �ð��ʰ���
-----------------*/

#include <iostream>
#include <string>
#include <vector>
std::string str, ex,ret;

int main() {
	std::cin >> str >> ex;
	int f_ex = ex.size()-1;
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ex[f_ex]&&f_ex<=ret.size()) {
			bool flag = true;
			for (int j = 1; j < f_ex+1; j++)
				if (ret[ret.size() - j ] != ex[f_ex - j])
				{
					flag = false;
					break;
				}
			if (!flag)
				ret += str[i];
			else
				ret = ret.erase(ret.size() - f_ex);
		}
		else
			ret += str[i];
	}
	if (ret.size())
		std::cout << ret << '\n';
	else
		std::cout << "FRULA\n";

	return 0;
}