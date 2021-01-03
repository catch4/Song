/*
Catch study 10����
����_�༺ �ͳ�
https://www.acmicpc.net/problem/1167
*/
/*-----------------
Ʋ�ȴ� ����
1. cost ����Ѱ� ���� vector�� �߰� -> �޸� �ʰ�
2. x,y,z�� ���� sort, ������ cost ��� -> �޸� �ʰ�
3. 2������ ���Լ��� �����Լ��� �ٲ�µ� �����

Ǯ��
�༺���ᶧ ���(ũ�罺Į) �����.

-----------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147000000
int n;
struct Pos {
	int x, y, z, p;
};
struct Cost {
	int c, n1, n2;
	bool operator<(const Cost& bb)const {
		return c < bb.c;
	}
	Cost() {};
	Cost(const int& t_c, const int& t_n1, const int& t_n2) {
		c = t_c, n1 = t_n1, n2 = t_n2;
	}
};

int cal_cost(Pos& a, Pos& b)
{
	return std::min(abs(a.x - b.x), std::min(abs(a.y - b.y), abs(a.z - b.z)));
}
void add_x(std::vector<Pos> pos, std::vector<Cost>& cost) {
	sort(pos.begin(), pos.end(), [](Pos& a, Pos& b) -> bool {return a.x < b.x; });
	for (int i = 0; i < n - 1; i++)
		cost[i] = Cost(cal_cost(pos[i], pos[i + 1]), pos[i].p, pos[i + 1].p);
}
void add_y(std::vector<Pos> pos, std::vector<Cost>& cost) {
	sort(pos.begin(), pos.end(), [](Pos& a, Pos& b) -> bool {return a.y < b.y; });
	for (int i = 0; i <n - 1; i++)
		cost[i + n - 1] = Cost(cal_cost(pos[i], pos[i + 1]), pos[i].p, pos[i + 1].p);
}
void add_z(std::vector<Pos> pos, std::vector<Cost>& cost) {
	sort(pos.begin(), pos.end(), [](Pos& a, Pos& b) -> bool {return a.z < b.z; });
	for (int i = 0; i < n - 1; i++)
		cost[i + (n - 1) * 2] = Cost(cal_cost(pos[i], pos[i + 1]), pos[i].p, pos[i + 1].p);
}

int find(std::vector<Pos>& a, const int& i) {
	if (a[i].p == i) return i;
	else return a[i].p = find(a, a[i].p);
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n;
	std::vector<Pos> pos(n);
	std::vector<Cost> cost((n - 1) * 3);
	int connected = 0, answer = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> pos[i].x >> pos[i].y >> pos[i].z;
		pos[i].p = i;
	}
	add_x(pos, cost);
	add_y(pos, cost);
	add_z(pos, cost);
	sort(cost.begin(), cost.end()); // �ּҰ����� ����
	for (int i = 0; i < cost.size(); i++) { // ���� �ȵǾ� ���� ��� �ּ� �ٸ����� �����ش�.
		int p1 = find(pos, cost[i].n1), p2 = find(pos, cost[i].n2);
		if (p1 != p2) {
			if (p1 < p2)
				pos[p2].p = p1;
			else
				pos[p1].p = p2;
			answer += cost[i].c;
			connected++;
			if (connected == n - 1)
				break;
		}
	}
	std::cout << answer << '\n';
}