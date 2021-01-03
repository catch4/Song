#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;
	std::vector<std::vector<int>> dp(land.size(), std::vector<int>(4, 0));
	
	for (int i = 0; i < 4; i++)
		dp[0][i] = land[0][i];

	for (int i = 1; i < land.size(); i++) 
		for (int j = 0; j < 4; j++) 
			for (int z = 0; z < 4; z++)
				if (z == j) continue;
				else dp[i][j] = std::max(dp[i][j], dp[i - 1][z] + land[i][j]);

	
	for (int i = 0; i < 4; i++)
		answer = std::max(answer, dp[land.size() - 1][i]);
	return answer;
}

/*
3
1 2 3 5
5 6 7 8
4 3 2 1
*/

int main() {
	int n;	std::cin >> n;
	std::vector<std::vector<int>> land(n, std::vector<int>(4, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			std::cin >> land[i][j];
	std::cout << solution(land) << std::endl;
}