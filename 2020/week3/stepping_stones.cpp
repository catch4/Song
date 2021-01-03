/*
Catch study 3주차
프로그래머스_징검다리 건너기
https://programmers.co.kr/learn/courses/30/lessons/64062
*/
/*
이분탐색
1. 연속된 k개의 돌다리가 mid 보다 작은 경우 불가능
2. index가 size()-k보다 큰 경우 나머지 돌다리가 k보다 작아서 볼 필요가 없음
3. 마지막으로 성공한 값(최대값) return
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool simulation(vector<int>& stones, const int& k, const int& threshold) {
	int idx = 0, cnt = 0;
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] < threshold)
			cnt++;
		else {
			if (i >= stones.size() - k) return true; // 2.
			cnt = 0;
		}
		if (cnt == k) return false; // 1.
	}
	return true;
}
int solution(vector<int> stones, int k) {
	int answer = 0, h = 0,l = 200000000;
	for (int i = 0; i < stones.size(); i++) {
		if (h < stones[i]) h = stones[i];
		if (l > stones[i]) l = stones[i];
	}
	if (l == h)
		return l;
	while (l <= h)
	{
		int mid = (l + h) / 2;
		if (simulation(stones,k,mid)) {
			answer = mid;
			l = mid + 1;
		}
		else h = mid - 1;
	}
	return answer;
}