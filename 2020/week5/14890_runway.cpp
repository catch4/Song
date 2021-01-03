/*
Catch study 5주차
백준_14890 경사로
https://www.acmicpc.net/problem/14890
*/
/*---------------------------
풀이
열,행 이전 idx가 큰 경우, 작은 경우 나눠서 구현

1. true인 경우 한 행에 대해 확인, false인 경우 한 열에 대해
2. 이전 idx가 큰 경우 
   l만큼 다음 idx들이 현재 idx와 동일한지 확인 및 체크
3. 이전 idx가 작은 경우
   l만큼 이전 idx들이 이전 idx와 동일한지 확인 및
   이미 체크 되어 있는 경우 경사로를 놓지 못하므로 false return
4. true 리턴 한 행,열에 대해 카운트
---------------------------*/
#include <iostream>
#include <vector>
#define vecs std::vector<std::vector<int>>
int n, l;

bool slope(vecs& map, int& idx, bool flag) {
	std::vector<bool> ck(n);
	if (flag)
	{
		for (int i = 1; i < n; i++) {
			if (map[idx][i] == map[idx][i - 1]) continue;
			else if (map[idx][i]==map[idx][i - 1]+1) {
				if (i - 1 < l - 1) return false;
				for (int j = i - 1; j >= i - l; j--)
					if (map[idx][i - 1] != map[idx][j] || ck[j]) return false;
					else ck[j] = 1;
			}
			else if (map[idx][i]+1 == map[idx][i - 1]) {
				if (n - i < l) return false;
				for (int j = i; j < i + l; j++)
					if (map[idx][i] != map[idx][j]) return false;
					else ck[j] = 1;
				i = i + l-1;
			}
			else return false;
		}
	}
	else {
		for (int i = 1; i < n; i++) {
			if (map[i][idx] == map[i-1][idx]) continue;
			else if (map[i][idx] == map[i-1][idx] + 1) {
				if (i - 1 < l - 1) return false;
				for (int j = i - 1; j >= i - l; j--)
					if (map[i-1][idx] != map[j][idx] || ck[j]) return false;
					else ck[j] = 1;
			}
			else if (map[i][idx] + 1 == map[i-1][idx]) {
				if (n - i < l) return false;
				for (int j = i; j < i + l; j++)
					if (map[i][idx] != map[j][idx]) return false;
					else ck[j] = 1;
				i = i + l - 1;
			}
			else return false;
		}
	}
	return true;
}

int main() {
	std::cin >> n >> l;
	int cnt = 0;
	vecs map(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			std::cin >> map[i][j];
		}
	for (int i = 0; i < n; i++) if (slope(map, i, true)) cnt++;
	for (int i = 0; i < n; i++) if (slope(map, i, false)) cnt++;
	std::cout << cnt << std::endl;
}