/*------------------------------------
 https://www.acmicpc.net/problem/1446

n의 범위가 작기 때문에 bfs와 브루트 포스로 접근
-------------------------------------- */
#include <iostream>
#include <vector>
#include <queue>
#define pi std::pair<int,int>
struct info {
	int start=0, end=0, len=0;
};

int main() {
	int n, d; std::cin >> n >> d;
	int min = d;
	std::vector<info> path(n);
	std::queue<pi> Q;

	for (int i = 0; i < n; i++)
		std::cin >> path[i].start >> path[i].end>>path[i].len;
	Q.push({ 0,0 });
	while (Q.size()) {

		pi now = Q.front();
		Q.pop();
		if (now.second + d - now.first < min)
			min = now.second + d - now.first;
		
		for (int i = 0; i < n; i++) {
			if (path[i].start < now.first || path[i].end>d) continue;
			
			int score = path[i].start - now.first + path[i].len + now.second;
			
			if (path[i].end == d && min > score) min = score;
			else Q.push({ path[i].end,score });
		}
	}
	std::cout << min << '\n';

	return 0;
}