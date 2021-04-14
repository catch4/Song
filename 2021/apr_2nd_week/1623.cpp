/*
Catch study 14/apr/2week
����_��������
https://www.acmicpc.net/problem/1623
*/
/*-----------------
Ǯ��
dp ���

�ش� ������ ���õǴ� ���, ���� �ȵǴ� ���� dp
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
	int ch = 0, noch = 0; // ���� �� ���, �ȵ� ���
	for (int c = 0; c < nodes[i].ch.size(); c++) {
		pi score = make_party_score(nodes, nodes[i].ch[c]);

		ch += score.second; // ���� ������ ���� �ȵ� ���� �� ���
		noch += score.first;
	}
	if (i) {
		if (nodes[i].score > 0)
			ch += nodes[i].score;
		if (ch > noch) // list print �� �� ���. ch < noch �� ���, �� ����� ��Ƽ�� ���� ����Ŵ
			nodes[i].status = true;

		return{ ch > noch ? ch : noch,noch }; // ���� �ƴҽ� �� ū ������ return
	}
	return{ ch + nodes[i].score,noch }; // �����
}

void make_party_list(std::vector<Node>& nodes, std::vector<int>& party_list, const int& i, const bool& flag) {
	if (flag) { // �ڽ��� ��簡 ���� �ϴ� ���
		for (int c = 0; c < nodes[i].ch.size(); c++) make_party_list(nodes, party_list, nodes[i].ch[c], false); // �Ʒ� ���� �� ���� x
	}
	else { // �ڽ��� ��簡 ���� �� �ϴ� ���
		if (nodes[i].status) // �����ϴ� �� �´� �� Ȯ��
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