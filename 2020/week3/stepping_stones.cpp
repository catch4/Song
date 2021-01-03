/*
Catch study 3����
���α׷��ӽ�_¡�˴ٸ� �ǳʱ�
https://programmers.co.kr/learn/courses/30/lessons/64062
*/
/*
�̺�Ž��
1. ���ӵ� k���� ���ٸ��� mid ���� ���� ��� �Ұ���
2. index�� size()-k���� ū ��� ������ ���ٸ��� k���� �۾Ƽ� �� �ʿ䰡 ����
3. ���������� ������ ��(�ִ밪) return
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