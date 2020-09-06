/*
Catch study 14주차
백준_생태학
https://www.acmicpc.net/problem/4358
*/
/*-----------------
풀이
1. 현재 입력받은 문자열이 이미 존재하는지 체크 -> hash / trie
2. 존재할 경우 횟수 +
3. 정렬이후 문자열이 카운트된 횟수 / 전체 입력받은 횟수 출력
-----------------*/

// hash, 2480kb, 136ms
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::unordered_map<std::string,int> mp;
struct Tree{
	std::string name;
	int cnt=1;
	Tree (){}
	Tree (std::string t_name){
		name=t_name;
	}
	bool operator<(const Tree& bb)const{
		return name<bb.name;
	}
};


int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::string str;
	std::vector<Tree> vecs;
	int sum=0;
	while(std::getline(std::cin,str,'\n') && str!=""){
		if(!mp[str]){ // 1.
			vecs.push_back(Tree(str));
			mp[str] = vecs.size();
		}
		else
			vecs[mp[str]-1].cnt+=1; // 2.
		sum+=1;
	}

	// 3.
	sort(vecs.begin(),vecs.end());
	std::cout<<std::fixed;
	std::cout.precision(4);
	for(int i=0;i<vecs.size();i++)
		std::cout<<vecs[i].name<<" "<<(double)vecs[i].cnt/sum*100.0<<'\n';

	return 0;
}


// trie _ 4172kb , 88ms
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

const int MAX = 128 - 32;
struct Trie {
	bool finish=0;
	int idx=-1;
	Trie* next[MAX];
	Trie() {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < MAX; i++)
			if (next[i]) delete next[i];
	}

	void insert(const char* key,const int& cnt) {
		if (*key ==0) {
			finish = 1;
			idx = cnt;
		}
		else {
			if (next[(*key - 32)]==NULL)
				next[(*key - 32)] = new Trie;
			next[(*key - 32)]->insert(key + 1,cnt);
		}
	}

	Trie* find(const char* key) {
		if (*key==0) return this;

		if (next[(*key - 32)]==NULL) return NULL;

		return next[(*key - 32)]->find(key + 1);
	}
};

struct Tree {
	std::string name;
	int cnt = 1;
	Tree() {}
	Tree(const std::string& t_name)
	{
		name = t_name;
	}
	bool operator<(const Tree& bb)const {
		return name < bb.name;
	}
};

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	Trie trie;
	std::string str;
	std::vector<Tree> vecs;
	int sum = 0;
	while (std::getline(std::cin, str, '\n') && str != "") {
		Trie* now = trie.find(str.c_str());
		if (now) {
			vecs[now->idx].cnt += 1; // 1.
		}
		else {
			trie.insert(str.c_str(), vecs.size()); // 2.
			vecs.push_back(Tree(str));
		}
		sum++;
	}
	// 3.
	sort(vecs.begin(), vecs.end());
	std::cout << std::fixed;
	std::cout.precision(4);
	for (int i = 0; i<vecs.size(); i++)
		std::cout << vecs[i].name << " " << (double)vecs[i].cnt / sum*100.0 << '\n';

	return 0;
}
