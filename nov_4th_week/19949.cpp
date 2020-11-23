// 브루트포스로 풀었음
// https://www.acmicpc.net/problem/19949
#include <iostream>

int solution[10],cnt=0,answer[10];

void dfs(int sum,int now) {
	if (now == 10)
	{
		if (sum >= 5)
			cnt += 1;
	}
	else {
		for (int i = 1; i <= 5; i++)
		{
			if (now >= 2) {
				if (answer[now - 1] == i &&answer[now - 2] == i) continue;
			}
			answer[now] = i;
			if (i == solution[now])
				dfs(sum + 1, now+1);
			else
				dfs(sum, now+1);
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++) std::cin >> solution[i];
	dfs(0, 0);
	std::cout << cnt << '\n';
	return 0;
}