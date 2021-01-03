/*
Catch study 6주차
백준_3020 개똥벌레
https://www.acmicpc.net/problem/3020
*/
/*
틀렸던 이유 - index 마다 ++ 해줘서 시간초과남

sorting 때문에 시간초과 될 줄 알았는데 안됬음...

1. 크기대로 sorting
2. lower_bound 사용해서 h 위치 마다 벽개수구함
3. 최소값과 동일할 경우 cnt
4. 최신화 갱신 될 때는 cnt도 1로 갱신
*/
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, h, cur,min=2147000000, cnt = 1;
	std::cin >> n >> h;
	std::vector<int> up(n/2),down(n/2);
	for (int i = 0; i < n / 2; i++)
		std::cin >> down[i] >> up[i];
	sort(up.begin(), up.end());
	sort(down.begin(), down.end());

	for (int i = 0; i < h; i++) {
		int u = up.end() - std::lower_bound(up.begin(), up.end(), i + 1); // 1.
		int d = down.end() - std::lower_bound(down.begin(), down.end(), h - i); // 2.
		if (u + d == min) cnt++; // 3.
		else if (u + d < min) { // 4.
			min = u + d;
			cnt = 1;
		}
	}
	std::cout << min << " " << cnt << '\n';
	return 0;
}