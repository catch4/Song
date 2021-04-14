/*
Catch study 14/apr/2week
백준_유럽여행
https://www.acmicpc.net/problem/1623
*/
/*-----------------
풀이
dp 사용

해당 직원이 선택되는 경우, 선택 안되는 경우로 dp
-----------------*/
#include <iostream>
#include <vector>
#define pi std::pair<int,int>

struct Node {
	int score = 0;
	bool status = false;
	std::vector<int> ch;
};

pi make_party_score(std::vector<Node>& nodes,const int& i) {
	int ch = 0, noch = 0; // 선택 된 경우, 안된 경우
	for (int c = 0; c < nodes[i].ch.size(); c++) {
		pi score = make_party_score(nodes, nodes[i].ch[c]);

		ch += score.second; // 부하 직원의 선택 안된 경우와 된 경우
		noch += score.first;
	}
	if (i) {
		if (nodes[i].score > 0)
			ch += nodes[i].score;
		if (ch > noch) // list print 할 때 사용. ch < noch 인 경우, 이 사람은 파티에 포함 못시킴
			nodes[i].status = true;

		return{ ch > noch ? ch : noch,noch }; // 사장 아닐시 더 큰 값으로 return
	}
	return{ ch + nodes[i].score,noch }; // 사장용
}

void make_party_list(std::vector<Node>& nodes, std::vector<int>& party_list, const int& i, const bool& flag) {
	if (flag) { // 자신의 상사가 참석 하는 경우
		for (int c = 0; c < nodes[i].ch.size(); c++) make_party_list(nodes, party_list, nodes[i].ch[c], false); // 아래 직원 은 참여 x
	}
	else { // 자신의 상사가 참석 안 하는 경우
		if (nodes[i].status) // 참여하는 거 맞는 지 확인
			party_list[i]=1;
		for (int c = 0; c < nodes[i].ch.size(); c++) make_party_list(nodes, party_list, nodes[i].ch[c], nodes[i].status);
	}
}


int main() {
	int n; std::cin >> n;
	std::vector<Node> nodes(n);
	std::vector<int> party_list(n);
	std::vector<int> party_list2(n);

	for (int i = 0; i < n; i++) std::cin >> nodes[i].score;
	for (int i = 1; i < n; i++) {
		int p; std::cin >> p;
		nodes[p - 1].ch.push_back(i);
	}
	nodes[0].status = true;
	pi score = make_party_score(nodes, 0);
	std::cout << score.first << " " << score.second << '\n';
	make_party_list(nodes, party_list, 0, false);
	make_party_list(nodes, party_list2, 0, true);
	for (int i = 0; i < n; i++)
		if (party_list[i]) std::cout << i + 1 << " ";
	std::cout << "-1\n";
	for (int i = 0; i < n; i++)
		if (party_list2[i]) std::cout << i + 1 << " ";
	std::cout << "-1\n";
	return 0;
}