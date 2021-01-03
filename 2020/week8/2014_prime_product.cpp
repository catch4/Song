/*
Catch study 8����
����_2014 �Ҽ��� ��
https://www.acmicpc.net/problem/2014
*/
/*-----------------------------
Ʋ�ȴ� ����
1. �޸��ʰ�
2. �ִ밪 ���� �߸���
	line 51�� if(n-cnt<= Q.size()*),
	line 56�� if (!flag) max = std::max(max, pu*Prime[k-1])�� �����ߴµ� pu*Prime[k-1]�� long long�� �Ѵ°�찡 �ִ°� ����.

Ǯ�� - 1 (ȥ�� Ǭ��) 
�켱���� ť �̿��ؼ� Ǯ��
1. Q�� ũ�Ⱑ n���� ���� ���� ��� �ִ밪 ���
2. n���� Ŀ���� �� �ִ밪 ���� ���� ���� Q�� ���� ����

Ǯ�� - 2 (�ٸ� �ڵ� ����)
�̷��� ����� humble number��� �ϴ� �� ����.
1. ���� ������ ���μ� �߿� �ش� �Ҽ��� ������ �������� Q�� �ִ´�. -> �̷��� �ϸ� �ߺ��� ���� �� �ִ�.
------------------------------*/
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <set>
#include <algorithm>
#define ll long long
int main() {
	std::ios::sync_with_stdio(false); std::cout.tie(NULL); std::cin.tie(NULL);
	int k, n,cnt=0; std::cin >> k >> n;
	std::vector<int> Prime(k);
	std::set<ll> set;
	bool flag = false;
	
	std::priority_queue<ll,std::vector<ll>,std::greater<ll>> Q;
	for (int i = 0; i < k; i++) {
		std::cin >> Prime[i];
		Q.push((ll)Prime[i]);
	}
	ll max = Prime[k - 1] * Prime[k - 1];
	
	while (1) {
		ll now = Q.top();
		Q.pop();
		cnt++;
		if (cnt == n) {
			std::cout << now << '\n';
			break;
		}
		if (n<Q.size()) flag = true;
		for (int i = 0; i < k; i++) {
			ll pu = now*(ll)Prime[i];
			if (pu > ((ll)1 << 32)) break;
			if (set.find(pu) != set.end()) continue;
			if (!flag)	max = std::max(max, pu);
			else if (pu > max) break;
			Q.push(pu);
			set.insert(pu);
		}
	}
	return 0;
}

//-----------------------------------------------------�ٸ� Ǯ�� ����-------------------------
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define ll long long
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, k; std::cin >> k >> n;
	std::vector<int> Prime(k);
	std::priority_queue<ll, std::vector<ll>, std::greater<ll>> Q;
	ll answer;
	for (int i = 0; i < k; i++) {
		std::cin >> Prime[i];
		Q.push(Prime[i]);
	}
	while (n--) {
		answer = Q.top();
		Q.pop();
		for (int i = 0; i < k; i++)
		{
			Q.push(answer * Prime[i]);
			if (!(answer%Prime[i])) break; // 1.
		}
	}
	std::cout << answer << '\n';
	return 0;
}