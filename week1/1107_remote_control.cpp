/*
Catch study 1주차
백준_1107 리모컨
https://www.acmicpc.net/problem/1107
*/

#include <iostream>
#include <vector>
int dst;
bool brk_bt[10];
int min = 2147000000;

void search(std::vector<int>& vec, int now, int& cnt)
{
	if (now == vec.size())
	{
		int sum = 0, cur = 1, limit = vec.size() - cnt;

		// 숫자버튼 누르기
		for (int i = now - 1; i >= limit; i--)
		{
			sum += cur*vec[i];
			cur *= 10;
		}
		// sum-dst는 +나 - 누른개수, cnt는 숫자 버튼 누른 개수
		int result = abs(sum - dst) + cnt;
		if (result < min) min = result;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			// 안 고장난 숫자버튼
			if (!brk_bt[i])
			{
				vec[now] = i;
				search(vec, now + 1, cnt);
				vec[now] = 0;
			}
		}
	}
}

int main() {
	int n, tmp; std::cin >> dst >> n;
	int simple = abs(100 - dst), cnt = 1,cnt_limit; // simple = +나 -로만 가는 경우
	for (int i = 0; i < n; i++) { // 고장난 버튼 입력
		std::cin >> tmp;
		brk_bt[tmp] = 1;
	}
	// dst보다 자리수 하나 더 큰거부터 하나 더 작은거까지 확인
	for (int i = 1; dst / i > 0; i *= 10) cnt++; 
	cnt_limit = (cnt - 3) >= 0 ? cnt-3 : 0; 
	
	std::vector<int> vec(cnt);
	for (int i = 0; cnt >cnt_limit; i++)
	{
		search(vec, i, cnt);
		cnt--;
	}
	if (min < simple) std::cout << min;
	else std::cout << simple;
	return 0;
}