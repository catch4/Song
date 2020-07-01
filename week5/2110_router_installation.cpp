/*
Catch study 5주차
백준_2110 공유기 설치
https://www.acmicpc.net/problem/2110
*/
/*---------------------------
이분탐색으로 풀었다.
sync 한거랑 안한거랑 속도 3배차이난다.
확인해보니까 ret 변수 선언 안하고 r을 print 해도 된다.

이분 탐색시에는 원하는 간격만큼의 차이가 가능한지만 확인했다.
---------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
int n, c;
bool check(std::vector<int>& homes, const int& num)
{
	int tmp = c-1,cur=0;
	for (int i = 1; i < n; i++) {
		if (homes[i] - homes[cur] >= num) {
			cur = i;
			tmp -= 1;
			if (!tmp) return true;
		}
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int l=1,r=1000000000,ret=1; std::cin >> n >> c;
	std::vector<int> homes(n);
	for (int i = 0; i < n; i++) std::cin >> homes[i];
	sort(homes.begin(), homes.end());
	while(l<=r)
	{
		int mid = (l + r) / 2;
		if (check(homes, mid)) {
			l = mid + 1;
			ret = mid;
		}
		else r = mid - 1;
	}
	std::cout << ret << std::endl;
}