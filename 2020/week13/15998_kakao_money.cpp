/*
Catch study 13주차
백준_카카오머니
https://www.acmicpc.net/problem/15998
*/
/*-----------------
틀림 아직도 이해 안감

생각한 풀이
나머지는 동일하고 충전이 일어났을 때 남은 금액중 최대값을 기준으로 체크함
그런데 통과코드는 남은 금액중 최소값을 기준으로 체크함

3
1500 1500
-1600 700
-900 200
m=400 나오는데 2번째에서 res가 300 나와야 하므로 -1이 정답 아닌가
-----------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define cll const long long&
#define ll long long
int n;
ll m;

ll gcd(cll a, cll b) {
	if (!b)	return a;
	else return gcd(b, a%b);
}

int main() {
	std::cin >> n;
	ll m_res = pow(10,18)*9,bef=0;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		ll oper, res; std::cin >> oper >> res;
		if (m == -1) continue;
		if (oper >= 0 || bef >= abs(oper))
		{
			if (bef + oper != res) m = -1;
		}
		else{
			if (res != 0 && res < m_res)
			{
				flag = true;
				m_res = res;
			}
			if (!m) m = res - oper - bef;
			else {
				ll now_m = res - oper - bef;
				m = now_m > m ? gcd(now_m, m) : gcd(m, now_m);
			}
			if (m_res >= m && flag) m = -1;
		}
		bef = res;
	}
	if (!m)
		std::cout << 1 << '\n';
	else
		std::cout << m << '\n';
}

