/*
Catch study 31/mar/4week
백준_16434 드래곤 앤 던전
https://www.acmicpc.net/problem/16434

구현+이분탐색인줄 알았는데, 그냥 이분탐색
*/

#include<iostream>
#include<vector>
#include <algorithm>
struct Info {
	int t;
	long long a, h;
};

bool is_clear(long long atk,const long long& max_hp, std::vector<Info>& room) {
	long long now_hp = max_hp;
	for (int i = 0; i < room.size(); i++) {
		if (room[i].t == 1) {
			long long atk_num = room[i].h / atk - 1;
			if (room[i].h % atk)
				atk_num += 1;
			if (now_hp <= atk_num*room[i].a)
				return false;
			now_hp -= atk_num*room[i].a;
		}
		else {
			now_hp = std::min(now_hp + room[i].h, max_hp);
			atk += room[i].a;
		}
	}
	return true;
}

int main() {
	int n;
	long long atk,answer=0;
	std::cin >> n >> atk;
	std::vector<Info> room(n);
	for (int i = 0; i < n; i++) {
		std::cin >> room[i].t >> room[i].a >> room[i].h;
	}
	long long l = 0, r = (1LL << 62);
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (is_clear(atk, mid, room)) {
			r = mid - 1;
			answer = mid;
		}
		else
			l = mid + 1;
	}
	std::cout << answer << '\n';
	return 0;
}