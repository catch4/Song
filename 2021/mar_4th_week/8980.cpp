/*
Catch study 31/mar/4week
백준_8980 택배
https://www.acmicpc.net/problem/8980

받는 마을이 적은순으로, 보내는 마을이 적은순으로 정렬
남은 공간보고 가능한 경우 결과에 더함.
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
				num = std::min(num,pad[j]); // 시작~도착 마을 갈때, 남은 공간중 최소값 찾기
			for (int j = box[i].d - 1; j >= box[i].s; j--)
				pad[j] -= num; // 최소값 일정하게 빼주기
			answer += num;
		}
	}
	
	std::cout << answer << '\n';

}