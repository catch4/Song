/*
Catch study 7����
����_6209 ���ڸ� �ָ��ٱ�
https://www.acmicpc.net/problem/6209
*/
/*
Ʋ�ȴ� ����
�� ���� �ϴ� �κ��� dfs�� ����
-> �ð��ʰ�

Ǯ��
�����ϰ� �̺�Ž������ ����
*/
#include <iostream>
#include <vector>
#include <algorithm>
int d, n, m,l = 1, r,mid;

bool check(std::vector<int>& vec) {
	int src = 0, dst = 1,cnt=0;
	while (dst < vec.size() && cnt <= m) {
		if (vec[dst] - vec[src] < mid) cnt++;
		else src=dst;
		dst++;
		}
	if (cnt > m) return false;
	else return true;
}

int main() {
	std::ios::sync_with_stdio(false); std::cout.tie(NULL); std::cin.tie(NULL);
	std::cin >> d >> n >> m;
	r = d;
	std::vector<int> vec(n+2);
	int result = 0;
	vec[0] = 0;
	vec[n + 1] = d;
	for (int i = 1; i <= n; i++) std::cin >> vec[i];
	sort(vec.begin(), vec.end());
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(vec)) {
			l = mid + 1;
			result = mid;
		}
		else 
			r = mid-1;
	}
	std::cout << result << '\n';
	return 0;
}