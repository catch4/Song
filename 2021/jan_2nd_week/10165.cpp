/*
Catch study 21/jan/2week
����_�����뼱
https://www.acmicpc.net/problem/10165
*/
/*-----------------
Ǯ�� - fail
- ���� ���� ��������, ���� ���� ������������ ����
- dq�� ���� �� �� ���� ���� ���� ���� ���� ������ ��� ���� ��
- dq�� ���� ���� �Ѿ ���ں��� ���� ���� ���� ����
( ���� ��� �������� 9, �������� 4 �� ��찡 max_val, �� ��� ���� ���� 0~3�̰� ���� ������ 4������ ���� 9~4 ���̿� ���Ե�)
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
