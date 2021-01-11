/*
Catch study 21/jan/2week
¹éÁØ_¶±Àå¼ö¿Í È£¶ûÀÌ
https://www.acmicpc.net/problem/10165
*/
#include <iostream>
#include <vector>

#define vec2d std::vector<std::vector<int>>
#define vec3d std::vector<std::vector<std::vector<int>>>
int n;
bool ck[1001][10];
bool dfs(vec2d& nums,vec3d& chil,const int& idx, const int& idx2) {
	ck[idx][idx2] = 1;
	if (!idx) {
		std::cout << nums[idx][idx2] << '\n';
		return true;
	}
	else {
		for (int i = 0; i < chil[idx][idx2].size(); i++) {
			if (ck[idx - 1][chil[idx][idx2][i]]) continue;
			if (dfs(nums, chil, idx - 1, chil[idx][idx2][i]))
			{
				std::cout << nums[idx][idx2] << '\n';
				return true;
			}
		}
	}
	return false;
}

int main() {
	std::cin >> n;
	std::vector<std::vector<int>> nums(n);
	std::vector<std::vector<std::vector<int>>> chil(n);
	for (int i = 0; i < n; i++) {
		int m;  std::cin >> m;
		chil[i].resize(m);
		for (int j = 0; j < m; j++) {
			int num; std::cin >> num;
			nums[i].push_back(num);
			if (i) {
				for (int z = 0; z < nums[i - 1].size(); z++)
					if (nums[i][j] != nums[i - 1][z])
						chil[i][j].push_back(z);
			}
		}
	}
	if (n>1) {
		for (int i = 0; i < nums[n - 1].size(); i++) {
			if (chil[n - 1][i].size()) {
				if (dfs(nums, chil, n - 1, i)) {
					return 0;
				}
			}
		}
	}
	else {
		std::cout << nums[0][0] << '\n';
		return 0;
	}
	std::cout << -1 << '\n';
	return 0;
}