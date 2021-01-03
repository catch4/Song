#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
	int n, m; std::cin >> n >> m;
	std::vector<std::vector<int>> pre(n);
	std::vector<int> post(n);
	std::priority_queue<int> Q;
	for (int i = 0; i < m; i++) {
		int a, b; std::cin >> a >> b;
		pre[a-1].push_back(b - 1);
		post[b - 1] += 1;
	}

	for (int i = 0; i < n; i++) {
		if (pre[i].size())
			sort(pre[i].begin(), pre[i].end());
		if (!post[i])
			Q.push(-i);
	}
	while (!Q.empty()) {
		int now = -1*Q.top();
		std::cout << now+1 << ' ';
		Q.pop();
		for (int i = 0; i < pre[now].size(); i++)
		{
			post[pre[now][i]] -= 1;
			if (!post[pre[now][i]]) Q.push(-1*pre[now][i]);
		}
	}
	return 0;
}