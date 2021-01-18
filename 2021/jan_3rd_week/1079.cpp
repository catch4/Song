/*
Catch study 21/jan/3week
백준_마피아
https://www.acmicpc.net/problem/1079

구현 및 브루트포스
참가자의 번호는 0부터 시작이었다....
*/

#include <iostream>
#include <vector>
#define vec2d std::vector<std::vector<int>>

int answer,k,n;
void dfs(std::vector<int>& vec,
	std::vector<bool>& ck,
	vec2d& mp,int cnt,int res, const bool& day) {
	if(res==1&&!ck[k]){
		if (cnt > answer) answer = cnt;
		return;
	}
	if (day) {
		int max_val=0, idx=0;
		for (int i = 0; i < n; i++) {
			if (ck[i]) continue;
			if (vec[i] > max_val)
			{
				idx = i;
				max_val = vec[i];
			}
		}
		if (idx == k) {
			if (cnt > answer) answer = cnt;
			return;
		}
		ck[idx] = 1;
		dfs(vec, ck, mp, cnt,res-1, !day);
		ck[idx] = 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (i != k && !ck[i]) {
				ck[i] = 1;
				for (int j = 0; j < n; j++) {
					vec[j] += mp[i][j];
				}
				dfs(vec, ck, mp, cnt+1,res-1, !day);
				ck[i] = 0;
				for (int j = 0; j < n; j++) {
					vec[j] -= mp[i][j];
				}
			}
		}
	}
}

int main() {
	std::cin >> n;
	std::vector<int> vec(n);
	std::vector<bool> ck(n);
	vec2d mp(n, std::vector<int> (n,0));
	
	for (int i = 0; i < n; i++)
		std::cin >> vec[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> mp[i][j];
	std::cin >> k;

	dfs(vec, ck, mp, 0,n, n % 2);
	std::cout << answer << '\n';
	return 0;
}