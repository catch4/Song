/*
Catch study 14주차
백준_개미굴
https://www.acmicpc.net/problem/14725
*/
/*-----------------
풀이
트라이로 구현 했으나 char 단위로 저장해서인지 메모리 너무 먹음
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
	void print(const int& cnt, bool flag) { // flag 하위라서 -- 출력해야 하는 경우
		for (int i = 0; i < 96; i++) {
			if (next[i]) { // " "이 있는 경우 = 하위 있음
				if (!i) {
					next[i]->print(cnt + 1, true); // 
				}
				else {
					if (flag) { // 하위라서 -- 출력
						for (int i = 0; i < (cnt-1) * 2; i++)
							std::cout << '-';
					}
					std::cout << (char)(i + 32);
					if (finish) // 단어 종료시 \n 출력
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
	// 2 KIWI BANANA 일 경우 "KIWI"랑 "KIWI BANANA" insert
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