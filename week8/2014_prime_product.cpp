/*
Catch study 8주차
백준_2014 소수의 곱
https://www.acmicpc.net/problem/2014
*/
/*-----------------------------
틀렸던 이유
1. 메모리초과
2. 최대값 설정 잘못함
	line 51을 if(n-cnt<= Q.size()*),
	line 56을 if (!flag) max = std::max(max, pu*Prime[k-1])로 설정했는데 pu*Prime[k-1]가 long long을 넘는경우가 있는것 같다.

풀이 - 1 (혼자 푼거) 
우선순위 큐 이용해서 풀이
1. Q의 크기가 n보다 작을 때는 계속 최대값 계산
2. n보다 커졌을 때 최대값 보다 높은 수는 Q에 넣지 않음

풀이 - 2 (다른 코드 참고)
이러한 출력을 humble number라고 하는 것 같다.
1. 현재 숫자의 소인수 중에 해당 소수가 존재할 때까지만 Q에 넣는다. -> 이렇게 하면 중복을 피할 수 있다.
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

//-----------------------------------------------------다른 풀이 참고-------------------------
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