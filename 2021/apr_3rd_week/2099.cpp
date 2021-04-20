/*
Catch study 21/apr/3week
백준_The game of death
https://www.acmicpc.net/problem/2099
*/
/*-----------------
못풀고 인터넷 참고
행렬의 재귀 연산과 동일하게 한다.
-----------------*/
#include <iostream>
#include <vector>
#define vec2d std::vector<std::vector<bool>>

int n, k, m;

vec2d cal(const vec2d&a, const vec2d&b) {
	vec2d c(n, std::vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (a[i][k] & b[k][j]) {
					c[i][j] = true;
				}
			}
		}
	}
	return c;
}
vec2d recur(vec2d graph,int k) {
	vec2d answer(n, std::vector<bool>(n));
	for (int i = 0; i < n; i++) answer[i][i] = 1;
	while (k > 0) {
		if (k % 2) answer = cal(answer, graph);
		graph = cal(graph, graph);
		k /= 2;
	}
	return answer;
}

int main() {
	std::cin >> n >> k >> m;
	vec2d graph(n, std::vector<bool>(n));
	for (int i = 0; i < n; i++) {
		int a, b; std::cin >> a >> b;
		graph[i][a - 1] = 1;
		graph[i][b - 1] = 1;

	}
	vec2d answer = recur(graph,k);
	for (int i = 0; i < m; i++) {
		int start, end; std::cin >> start >> end;
		if (answer[start - 1][end - 1]) std::cout << "death\n";
		else std::cout << "life\n";
	}
	return 0;
}