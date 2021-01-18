/*
Catch study 21/jan/3week
백준_먹이사슬
https://www.acmicpc.net/problem/2532

fail, refer = https://ioqoo.tistory.com/51

1. 시작지점은 오름차순, 끝나는 지점은 내림차순으로 정렬
2. 끝나는 지점으로 lower bound를 진행하며 end()가 아닐 경우 교체(먹이 사슬에 포함안되는 경우)
   end()일 경우는 추가(먹이 사슬에 포함되는 경우)
*/

#include <iostream>
#include <vector>
#include <algorithm>
struct Animal{
	int start, end;
	bool operator<(const Animal& bb)const {
		if (start == bb.start) return end > bb.end;
		return start < bb.start;
	}
	bool operator==(const Animal& bb)const {
		if (start == bb.start && end == bb.end) return true;
		return false;
	}
};

int main() {
	int n; std::cin >> n;
	std::vector<Animal> vec(n);
	std::vector<int> lis;
	for (int i = 0; i < n; i++)
	{
		int idx; std::cin >> idx >> vec[i].start >> vec[i].end;
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	lis.push_back(vec[0].end);
	for (int i = 1; i < vec.size(); i++)
	{
		int curr = vec[i].end;
		auto it = std::lower_bound(lis.begin(), lis.end(), curr, [](const int& a, const int&b) {return a >= b; });
		if (it == lis.end()) lis.push_back(curr);
		else *it = curr;
	}
	std::cout << lis.size() << '\n';
	return 0;
}