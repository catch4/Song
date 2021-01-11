/*
Catch study 21/jan/2week
백준_버스노선
https://www.acmicpc.net/problem/10165
*/
/*-----------------
풀이 - fail
- 시작 지점 오름차순, 도착 지점 내림차순으로 정렬
- dq에 넣을 때 맨 뒤의 도착 지점 보다 낮은 숫자인 경우 포함 됨
- dq의 앞쪽 부터 넘어간 숫자보다 낮은 도착 지점 삭제
( 예를 들어 시작지점 9, 도착지점 4 인 경우가 max_val, 이 경우 시작 지점 0~3이고 도착 지점이 4이하인 경우는 9~4 사이에 포함됨)
-----------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

struct Info {
	int src, dst, idx;
	bool operator<(const Info& bb)const {
		if (bb.src == src) return bb.dst < dst;
		return bb.src > src;
	}
};

int n, m;

int main() {
	std::ios::sync_with_stdio(false);std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> m;
	std::vector<Info> vec(m);
	int max_val = 0;
	for (int i = 0; i < m; i++) {
		int src, dst; std::cin >> src >> dst;
		if (src > dst) {
			max_val = std::max(max_val, dst);
			dst += n;
		}
		vec[i].src = src,vec[i].dst=dst,vec[i].idx=i+1;
	}
	sort(vec.begin(), vec.end());
	
	std::deque<Info> dq;
	
	for (int i = 0; i <m; i++)
		if (dq.empty() || dq.back().dst < vec[i].dst)
			dq.push_back(vec[i]);
	while (!dq.empty() && dq.front().dst <= max_val) dq.pop_front();

	sort(dq.begin(), dq.end(), [&](Info& aa, Info& bb) {return aa.idx < bb.idx;});
	while (!dq.empty()) {
		std::cout << dq.front().idx << " ";
		dq.pop_front();
	}
	return 0;
}
