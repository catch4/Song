/*
Catch study 14����
����_���̱�
https://www.acmicpc.net/problem/14725
*/
/*-----------------
Ǯ��
Ʈ���̷� ���� ������ char ������ �����ؼ����� �޸� �ʹ� ����
-----------------*/
#include <iostream>
#include <string>
#include <vector>

struct Trie {
	bool finish = 0;
	int idx = -1,depth;
	Trie* next[96];
	Trie(){
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 96; i++) 
			if(next[i])
				delete next[i];
	}
	void insert(const char* ch) {
		if (*ch == 0) return;
		else {
			if (*(ch + 1) == 0) {
				finish = 1;
			}
			if (next[(*ch - 32)] == 0)
				next[(*ch - 32)] = new Trie;
			next[(*ch - 32)]->insert(ch + 1);
		}
	}

	Trie* find(const char* ch) {
		if (*ch == 0) return this;
		if (next[(*ch - 32)] == NULL) return NULL;
		return next[(*ch - 32)]->find(ch);
	}
	void print(const int& cnt, bool flag) { // flag ������ -- ����ؾ� �ϴ� ���
		for (int i = 0; i < 96; i++) {
			if (next[i]) { // " "�� �ִ� ��� = ���� ����
				if (!i) {
					next[i]->print(cnt + 1, true); // 
				}
				else {
					if (flag) { // ������ -- ���
						for (int i = 0; i < (cnt-1) * 2; i++)
							std::cout << '-';
					}
					std::cout << (char)(i + 32);
					if (finish) // �ܾ� ����� \n ���
						std::cout << '\n';
					next[i]->print(cnt, false);
				}
			}
		}
	}
};

int main() {
	int n; std::cin >> n;
	std::string str;
	Trie trie;
	// 2 KIWI BANANA �� ��� "KIWI"�� "KIWI BANANA" insert
	for (int i = 0; i < n; i++)
	{
		int m; std::cin >> m;
		str = "";
		std::string n_str;
		for (int j = 0; j < m; j++) {
			std::cin >> n_str;
			str += " " + n_str;
			Trie* n_t = trie.find(str.c_str());
			if (!n_t)
				trie.insert(str.c_str());
		}
	}
	trie.print(0, 0);
}