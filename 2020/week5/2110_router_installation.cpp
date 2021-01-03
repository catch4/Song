/*
Catch study 5����
����_2110 ������ ��ġ
https://www.acmicpc.net/problem/2110
*/
/*---------------------------
�̺�Ž������ Ǯ����.
sync �ѰŶ� ���ѰŶ� �ӵ� 3�����̳���.
Ȯ���غ��ϱ� ret ���� ���� ���ϰ� r�� print �ص� �ȴ�.

�̺� Ž���ÿ��� ���ϴ� ���ݸ�ŭ�� ���̰� ���������� Ȯ���ߴ�.
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