/*
Catch study 6����
����_3020 ���˹���
https://www.acmicpc.net/problem/3020
*/
/*
Ʋ�ȴ� ���� - index ���� ++ ���༭ �ð��ʰ���

sorting ������ �ð��ʰ� �� �� �˾Ҵµ� �ȉ���...

1. ũ���� sorting
2. lower_bound ����ؼ� h ��ġ ���� ����������
3. �ּҰ��� ������ ��� cnt
4. �ֽ�ȭ ���� �� ���� cnt�� 1�� ����
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