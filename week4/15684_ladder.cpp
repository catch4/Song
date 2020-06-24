/*
Catch study 4주차
백준_15684 사다리 조작
https://www.acmicpc.net/problem/15684
*/
/*
------------------
이전에 생각한 규칙
------------------
한 라인에 가로줄이 짝수개여야 한다.
예외) 인접도 홀수면 가능하다
3 7 9
1 1
2 2
3 1
4 1
5 1
6 2
8 2
정답 7 1에 놓으며 되므로 1

---------
틀린 이유
---------
1. 브루트포스 말고 나름대로 규칙생각하면서
   짜봤는데 시간 2시간 정도걸리고 틀림
   다음날 브루트 포스로 하니까 30분도 안걸림 화남

2. 맨처음에는 dsf(vecs ladder)로 깊은복사,
   sync,tie 안한 상태 -> 
   dfs(vec& ladder)로 얕은복사, sync,tie 추가
   해서 시간초과 사라짐

3. 바보같이 dfs내의 for(int i=now+1)로 설정했었음


----
풀이
----
브루트포스로 함, dfs 내에서 중복 피하는 것 위주로 신경썼다.

1-1. dfs내에서 1번 사다리-> 2번 사다리와
	 2번 사다리-> 1번 사다리는 중복되기 때문에
	 오른쪽으로 가는 방향만 함.

1-2. 중복을 피하기 위해 n*h를 1차원으로 생각하고
	 i/n, i%n으로 y,x를 찾았는데 1-1의 이유로 제일 오른쪽은
	 볼필요 없어서 x==n-1일 때 continue

*/

#include <iostream>
#include <vector>
#include <stack>
#define vecs std::vector<std::vector<int>>
int n, m, h;
bool possible(vecs& ladder) {
	for (int i = 0; i < n; i++)
	{
		int num = i;
		for (int j = 0; j < h; j++)
		{
			if (!ladder[j][num]) continue;
			num += ladder[j][num];
		}
		if (num != i) return false;
	}
	return true;
}

bool dfs(vecs& ladder, const int& dst, const int& choiced, const int& now) {
	if (choiced == dst)
	{
		if (possible(ladder)) return true;
	}
	else
	{
		for (int i = now; i < n*h; i++)
		{
			int y = i / n, x = i%n;
			if (x == n - 1) continue; // 1-2.
			if (ladder[y][x]||ladder[y][x+1]) continue;
			else
			{
				ladder[y][x] = 1; // 1-1.
				ladder[y][x + 1] = -1; // 1-1.
				if(dfs(ladder, dst, choiced + 1, i+1)) return true;
				ladder[y][x] = 0;
				ladder[y][x + 1] = 0;
			}
		}
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> m >> h;
	vecs ladder(h, std::vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		int y, x; std::cin >> y >> x;
		ladder[y - 1][x - 1] = 1;
		ladder[y - 1][x] = -1;
	}
	for (int i = 0; i <= 3; i++)
	{
		if (dfs(ladder,i,0,0))
		{
			std::cout << i << '\n';
			return 0;
		}
	}
	std::cout << -1 << '\n';
	return 0;
}

