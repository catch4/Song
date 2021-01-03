/*
Catch study 7주차
백준_3430 용이산다
https://www.acmicpc.net/problem/3430
*/
/*
맨 처음에 유일한 답이 존재하는 줄 알았는데
가능한 답 중 하나를 출력하는 거였음
예를들어
2 4
0 0 0 1
예제는
YES
1 0 0
YES
0 1 0
YES
0 0 1
다 가능함.

틀림
메모리초과로 계속틀려서 블로그 글 보고 공부함
뒤에서 부터 채우는 방식으로 했는데
앞에서 부터 채워야 했음

1. 비가 안 오는날 set에 추가
2. 비가 오는날일 경우 가장 먼저 비가 안온날에 호수 비우고
   t날에 비온거 체크
   (이후에 동일한 호수에 비가오면 이날 이후에 비 안오는날 마셔야함)
3. 마신날은 set에서 제외
*/
#include <iostream>
#include <vector>
#include <set>
int n, m, t;
bool Is_OK(std::vector<int>& ck, std::vector<int>& ret) {
	std::set<int> s;
	for (int i = 0; i < m; i++) {
		std::cin >> t;
		if (t == 0) {
			s.insert(i);
			ret[i] = 0;
		}
		else {
			auto iter = s.upper_bound(ck[t - 1]);
			if (iter == s.end())
			{
				while (++i < m) {
					std::cin >> t;
				}
				return false;
			}
			// 2.
			ret[*iter] = t;
			ck[t - 1] = i;
			
			// 3.
			s.erase(iter); 
		}
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int z; std::cin >> z;
	while (z--) {
		std::cin >> n >> m;
		std::vector<int> ck(n, -1),ret(m,-1);
		if (Is_OK(ck, ret)) {
			std::cout << "YES\n";
			for (int i = 0; i < m; i++) if (ret[i] != -1) std::cout << ret[i] << " ";
			std::cout << '\n';
		}
		else std::cout << "NO\n";
	}
	return 0;
}