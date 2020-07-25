/*
Catch study 8����
����_9576 å �����ֱ�
https://www.acmicpc.net/problem/9576
*/
/*-----------------------------
Ǯ��
����
n=4, m=3, {1,2},{3,3},{3,4}�� ������ �� �� �켱���� ť�� ����
1. {1,2}�� �����ϹǷ� 1���� ������
2. 2�� �ǳʶ�
3. {3,3}�� �����ϹǷ� 3���� ������, {3,4}�� �������Ƿ� {3+1,4} ť�� ����
4. {4,4}�� �����ϹǷ� 4���� ������

������ �켱���� ť�� ����
�ӵ��� ���ͷ� �ϴ°� ����Ƚ�������� ���� ����

Ʋ�ȴ�����(�켱���� ť)
1. ������������ �����߾���

Ʋ�ȴ�����(����)
1. j�� i+1 ���� ������ �Ѱ��ָ� �ȵǴµ� �Ѱܹ���
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