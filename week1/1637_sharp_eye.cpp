/*
Catch study 1주차
백준_1637 중량제한
https://www.acmicpc.net/problem/1637
*/

#include <iostream>
#include <vector>
#include <algorithm>
struct dummy {
	int a, b, c;
	// 더미내에 num이하의 숫자 return
	int count(const int& num) {
		if (num < a) return 0;
		return (std::min(c,num) - a) / b+1;
	}
};

std::vector<dummy> vec;
int n;

int dummy_sum(const int& num) { // 모든 더미에서 num이하의 정수 카운트
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += vec[i].count(num);
	return sum;
}

int main() {
	int max = 0; std::cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> vec[i].a >> vec[i].c >> vec[i].b;
		if (max < vec[i].c) max = vec[i].c;
	}
	long long l = 0, h = max, mid,target; // l범위가 정수 범위 넘을 때 있어서 longlong으로 선언

	if (dummy_sum(max) % 2) { //제일 큰 숫자가 짝수면 더미내에 홀수인 정수가 없음
		while (l <= h)
		{
			mid = (h + l) / 2;
			if (dummy_sum(mid) % 2) {
				h = mid - 1;
				target = mid;
			}
			else
				l = mid + 1; 
		}
		std::cout << target << " " << dummy_sum(target) - dummy_sum(target - 1) << std::endl;
	}
	else
	{
		std::cout << "NOTHING" << std::endl;
	}
	return 0;
}