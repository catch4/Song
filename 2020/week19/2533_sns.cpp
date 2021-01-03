#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int color[1000000 + 1], cnt[2] = { 0,0 };

bool make_color(const int& a, const int& b) {
	if (color[a] && color[b]) return true;
	if (color[a]) {
		color[b] = 3 - color[a];
		cnt[2 - color[b]]++;
	}
	else if (color[b]) {
		color[a] = 3 - color[b];
		cnt[2 - color[a]]++;
	}
	else return false;
	return true;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n; std::cin >> n;
	std::queue<std::pair<int, int>> Q;
	color[1] = 1;
	for (int i = 0; i < n - 1; i++) {
		int a, b; std::cin >> a >> b;
		if (!make_color(a, b)) Q.push({ a,b });
	}
	while (!Q.empty()) {
		std::pair<int, int> now = Q.front();
		Q.pop();
		if (!make_color(now.first, now.second)) Q.push(now);
	}
	std::cout << std::min(cnt[0], cnt[1]);
}







#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int color[1000000 + 1], cnt[2] = { 0,0 };
std::vector<int> vec[1000000 + 1];

void dfs(const int&idx, const int& c) {
	cnt[2 - c]++;
	color[idx] = c;
	for (int i = 0; i < vec[idx].size(); i++) {
		if (!color[vec[idx][i]])
			dfs(vec[idx][i], 3 - c);
	}
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n; std::cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b; std::cin >> a >> b;
		vec[a].push_back(b);
	}
	dfs(1,1);
	std::cout << std::min(cnt[0], cnt[1]);
}