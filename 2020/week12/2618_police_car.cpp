/*
Catch study 12����
����_������
https://www.acmicpc.net/problem/2618
*/
/*-----------------
Ǯ��
dp
1. dp�� [1���� i��° �����ġ�ΰ��][2���� ...]�� �ּҰ�
2. ���°�� �⵿�ߴ� ���� �ٽ� �ּҰ� Ȯ���ϸ鼭 ���
-----------------*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define pi std::pair<int,int>
#define y first
#define x second
#define vec2d std::vector<std::vector<int>>
std::vector<pi> e;
int n, c;

int cal(const pi& src, const pi& dst) { // ��� ���
	return abs(src.x - dst.x) + abs(src.y - dst.y);
}

pi get_pos(const int& num, const bool& flag) { // ��ǥ return
	if (num) return e[num];
	if (flag)
		return{ 1,1 };
	return{ n,n };
}

int dfs(vec2d& dp, const int& i, const int& l, const int& r) { // 1. l�� 1��° ��, r�� 2��° ��
	if (i == c)
		return 0;
	else if (dp[l][r])
		return dp[l][r];
	else {
		pi l_pos = get_pos(l, true), r_pos = get_pos(r, false);

		return dp[l][r] = std::min(dfs(dp, i + 1, i + 1, r) + cal(e[i + 1], l_pos), dfs(dp, i + 1, l, i + 1) + cal(e[i + 1], r_pos)); // �ּҰ� �Ҵ�
	}
}

int main() {
	std::cin >> n >> c;
	e.resize(c + 1);
	vec2d dp(c, std::vector<int>(c, 0));

	for (int i = 0; i < c; i++)
		std::cin >> e[i + 1].y >> e[i + 1].x;
	int l = 0, r = 0;
	dfs(dp, 0, 0, 0); // 1.

	std::cout << dp[0][0] << '\n';
	for (int i = 1; i < c + 1; i++) {
		if (i == c) { // ������ ����� ����Ȱ� ��� dp ���� ���
			if (cal(e[c], get_pos(l, true)) < cal(e[c], get_pos(r, false)))
				std::cout << "1\n";
			else
				std::cout << "2\n";
		}
		else { // dp�� ������ �� �̿��ؼ� �⵿�� ���� Ȯ��
			if (dp[i][r] + cal(e[i], get_pos(l, true)) < dp[l][i] + cal(e[i], get_pos(r, false)))
			{
				l = i;
				std::cout << "1\n";
			}
			else {
				r = i;
				std::cout << "2\n";
			}
		}
	}
}