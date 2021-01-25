/*
Catch study 21/jan/4week
백준_20120 호반우와 리듬게임
https://www.acmicpc.net/problem/20120

for문을 돌며 아래 3개값 갱신
콤보 0일 경우 최대값 -> 두 번째 전과 첫 번째 전 상황에서 콤보가 1 이상 중 가장 큰 누적 값
콤보 1일 경우 최대값 -> 세 번째 전과 두 번째 전 상황에서 콤보가 1 이상 중 가장 큰 누적 값 + 현재 값
콤보 2 이상일 경우 최대값 -> 이전 값의 콤보가 1이상일 때 + 현재 값 * 콤보
*/
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n; std::cin >> n;
	long long n2_max = 0,n1_max=0, answer = 0;
	std::vector<long long> vec(n);
	std::cin >> vec[0];
	
	for (int i = 1; i < n; i++) {
		int num; std::cin >> num;
		long long now_max = -10000001;
		for (int j = i-1; j>=0 ; j--) {
			now_max = std::max(vec[j], now_max); 
			vec[j + 1] = vec[j] + (j + 2)*num;
		}
		vec[0] = std::max(n2_max, n1_max)+num; // 지금 콤보 1 일 경우 최대 값, 현재 n2_max는 세번째 전 콤보가 1 이상 중 가장 큰 누적값
		n2_max = n1_max; // n-2가 관여 되었을 때 최대값
		n1_max = now_max; // n-1이 관여 되었을 때 최대값
	}
	answer = std::max(answer, std::max(n2_max, n1_max)); // 지금 콤보 0 일 경우 최대 값
	for (int i = 0; i < n; i++) // 콤보 1 이상 일 때중 최대값
		answer = std::max(vec[i], answer); 
	std::cout << answer;
}