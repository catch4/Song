/*
Catch study 21/jan/3week
백준_보석
https://www.acmicpc.net/problem/2492

보석이 있는 x,y 조합으로 브루트 포스
*/

#include <iostream>
#include <vector>
#include <set>
#define pvec std::vector<std::pair<int,int>>
#define y first
#define x second

int main() {
	int n, m, t, k,answer=0; std::cin >> n >> m >> t >> k;
	pvec pos(t);
	std::pair<int, int> answer_pos;
	std::set<int> xset,yset;
	for (int i = 0; i < t; i++) {
		std::cin >> pos[i].x >> pos[i].y;
		xset.insert(pos[i].x);
		yset.insert(pos[i].y);
	}
	for (std::set<int>::iterator px = xset.begin(); px != xset.end(); px++) {
		int xpos=*px;
		if (xpos + k > n)
			xpos = n - k;
		for (std::set<int>::iterator py = yset.begin(); py != yset.end(); py++) {
			int ypos = *py, cnt = 0;
			if (ypos + k > m)
				ypos = m - k;
			for (int i = 0; i < t; i++) {
				if (xpos <= pos[i].x&&pos[i].x <= xpos + k &&
					ypos <= pos[i].y&&pos[i].y <= ypos + k) cnt+=1;
			}
			if (cnt > answer) {
				answer = cnt;
				answer_pos.x=xpos,answer_pos.y = ypos;
			}
		}
	}
	std::cout << answer_pos.x << " " << answer_pos.y+k << '\n';
	std::cout << answer << '\n';
}