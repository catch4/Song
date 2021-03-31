/*
Catch study 31/mar/4week
����_8980 �ù�
https://www.acmicpc.net/problem/8980

�޴� ������ ����������, ������ ������ ���������� ����
���� �������� ������ ��� ����� ����.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Box {
	int s, d, c;
	bool operator<(const Box& b) {
		if (d == b.d) return s < b.s;
		return d < b.d;
	}
};

int main() {
	int n, c, m,answer=0; std::cin >> n >> c >> m;
	std::vector<int> pad(n + 1,c);
	std::vector<Box> box(m);
	for (int i = 0; i < m; i++)
		std::cin >> box[i].s >> box[i].d >> box[i].c;

	sort(box.begin(), box.end());
	for (int i = 0; i < m; i++) {
		if (pad[box[i].s]) {
			int num = box[i].c;
			for (int j = box[i].d - 1; j >= box[i].s; j--)
				num = std::min(num,pad[j]); // ����~���� ���� ����, ���� ������ �ּҰ� ã��
			for (int j = box[i].d - 1; j >= box[i].s; j--)
				pad[j] -= num; // �ּҰ� �����ϰ� ���ֱ�
			answer += num;
		}
	}
	
	std::cout << answer << '\n';

}