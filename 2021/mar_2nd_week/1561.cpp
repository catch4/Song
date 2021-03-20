/*
Catch study 17/mar/3week
����_1561 ���� ����
https://www.acmicpc.net/problem/1561

���� �̺�Ž����
1. �̺�Ž�� ���� ���� (�̹� ź, Ȥ�� ���� Ÿ���ִ� �ο� + m�� n�̻��� ��)
2. ���� ���߷��� ���° ���̱ⱸ ���� ���
*/
#include <iostream>
#include <vector>

int n, m;

int calculate(std::vector<int>& rides, const long long& mid) {
	long long sum = 0;Ÿ
	for (int i = 0; i < rides.size(); i++) {
		sum += mid / rides[i];
		if (mid % rides[i])
			sum += 1;
		if (sum > n) break;
	}
	if (sum < n && sum + m >= n) return sum; // 1.
	else if(sum < n) return -1;
	else return 0;
}

void print_answer(std::vector<int>& rides, long long mid,const long long& sum) { //2.
	int ans = m,res = n-sum,i=0;
	while (res) {
		if (mid%rides[i] == 0) {
			res--;
			if (!res)
				ans = i + 1;
		}
		i += 1;
		if (i == m) {
			i = 0;
			mid += 1;
		}
	}
	std::cout << ans << '\n';
}

int main() {
	std::cin >> n >> m;
	long long l = 0, r = (1LL << 62);

	std::vector<int> rides(m);
	for (int i = 0; i < m; i++)
		std::cin >> rides[i];
	if (n <= m) print_answer(rides, 0, 0);
	else {
		while (l <= r) {
			long long mid = (l + r) / 2;

			int result = calculate(rides, mid);
			if (result > 0) {
				print_answer(rides, mid, result);
				break;
			}
			else if (!result)
				r = mid - 1;
			else
				l = mid + 1;

		}
	}
}