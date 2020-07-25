/*
Catch study 8주차
백준_9576 책 나눠주기
https://www.acmicpc.net/problem/9576
*/
/*-----------------------------
풀이
정렬
n=4, m=3, {1,2},{3,3},{3,4}로 들어왔을 때 다 우선순위 큐에 넣음
1. {1,2}가 존재하므로 1에게 나눠줌
2. 2는 건너뜀
3. {3,3}이 존재하므로 3에게 나눠줌, {3,4}가 남았으므로 {3+1,4} 큐에 넣음
4. {4,4}가 존재하므로 4에게 나눠줌

구현은 우선순위 큐가 쉬움
속도는 벡터로 하는게 정렬횟수때문에 좀더 빠름

틀렸던이유(우선순위 큐)
1. 내림차순으로 정렬했었음

틀렸던이유(벡터)
1. j가 i+1 보다 작으면 넘겨주면 안되는데 넘겨버림
------------------------------*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define pi std::pair<int,int>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t; std::cin >> t;
	while (t--) {
		int n, m, cnt = 0; std::cin >> n >> m;
		std::priority_queue<pi,std::vector<pi>,std::greater<pi>> Q;
		std::vector<bool> ck(n);
		for (int i = 0; i < m; i++)
		{
			int a, b; std::cin >> a >> b;
			Q.push({ a,b });
		}
		while (!Q.empty()) {
			pi now = Q.top();
			Q.pop();
			if (ck[now.first - 1] && now.first>= now.second) continue;
			else if (ck[now.first - 1]) {
				Q.push({ now.first + 1,now.second });
			}
			else {
				ck[now.first - 1] = 1;
				cnt += 1;
			}
		}
		std::cout << cnt << '\n';
	}
}


#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t; std::cin >> t;
	while (t--) {
		int n, m, cnt = 0; std::cin >> n >> m;
		std::vector<std::vector<int>> vec(n);
		std::vector<bool> ck(n);
		for (int i = 0; i < m; i++)
		{
			int a, b; std::cin >> a >> b;
			vec[a - 1].push_back(b - 1);
		}
		for (int i = 0; i < n-1; i++) {
			if (!vec[i].size()) continue;
			sort(vec[i].begin(), vec[i].end());
			int j=0;
			if (!ck[i]){
				j+=1;
				ck[i] = 1;
				cnt++;
			}
			for (; j < vec[i].size(); j++)
				if (vec[i][j] < i+1) continue;
				else vec[i + 1].push_back(vec[i][j]);
		}
		if (!ck[n - 1] && vec[n - 1].size()) cnt += 1;
		std::cout << cnt << '\n';
	}
}