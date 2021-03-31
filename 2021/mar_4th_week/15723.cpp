/*
Catch study 31/mar/4week
백준_15723 n단 논법
https://www.acmicpc.net/problem/15723

플로이드 와샬
*/

#include <iostream>
#include <vector>
#include <string>
bool ch[26][26];

int main()
{
	int n, m; std::cin >> n;
	std::cin.ignore();
	for (int i = 0; i < n; i++) {
		
		std::string str; std::getline(std::cin,str);
		ch[str[0] - 'a'][str[5] - 'a'] = 1;
	}

	for (int k = 0; k < 26; k++)
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++) {
				if (ch[i][k] && ch[k][j])
					ch[i][j] = 1;
			}


	std::cin >> m;
	std::cin.ignore();
	for (int i = 0; i < m; i++) {
		std::string str; std::getline(std::cin, str);

		if (ch[str[0] - 'a'][str[5] - 'a'])
			std::cout << "T\n";
		else
			std::cout << "F\n";
	}

	return 0;
}