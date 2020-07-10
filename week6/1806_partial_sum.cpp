/*
Catch study 6주차
백준_1806 부분합
https://www.acmicpc.net/problem/1806
*/
/*
이전에 풀었던 거라 한번에 통과할 줄 알았는데
중간에 for문 잘못설정해서 여러번 틀렸다.
누적합도 long long으로 안했었다.

틀렸던 이유 - for문 시작 범위를 idx부터 했어야 했다.

투포인터로 구현
1. 배열은 입력 받을 때 누적합으로 받는다.
2. 누적합이 s보다 낮은 idx 까지는 볼 필요 없어서 시작을 설정
3. 마지막 누적합이 s보다 낮을 경우 0 반환
4. 배열의 길이가 최소화 될때마다 갱신하고 다음 index 부터는
   최신화 된 배열의 길이 부터 확인해본다.
*/

#include <iostream>
#include <vector>
int n, s,idx;

int Find_sum(std::vector<long long>& sums) {
	int min = idx;
	for (int cur = idx; cur < n + 1; cur++)
	{
		for (int j = cur - min; j < cur; j++) // 4.
			if (sums[cur] - sums[j] >= s) min = cur - j;
			else break;
	}
	return min;
}

int main() {
	std::cin >> n >> s;
	idx = n;
	std::vector<long long> sums(n + 1);
	for (int i = 1; i < n + 1; i++) {
		int num; std::cin >> num;
		sums[i] = (long long)num + sums[i - 1]; // 1.
		if (sums[i] >= s && idx > i) idx=i; // 2.
	}
	if (sums[n] < s) std::cout << 0 << '\n'; // 3.
	else std::cout << Find_sum(sums) << '\n'; // 4.
	
	return 0;	
}