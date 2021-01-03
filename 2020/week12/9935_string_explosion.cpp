/*
Catch study 12주차
백준_문자열 폭발
https://www.acmicpc.net/problem/9935
*/
/*-----------------
풀이
폭발 문자열의 마지막 글자와 동일할때만 확인
substr 사용해서 재할당 하면 시간초과남
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