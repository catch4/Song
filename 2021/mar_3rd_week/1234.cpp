#include <iostream>
#include <vector>

long long dp[10][100][100][100];
long long comb[11][11];
int n;
long long nCr(const int& n, const int& r) {
	if (comb[n][r] != 0) return comb[n][r];
	if (n == r || r == 0) return 1;
	else return comb[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

long long dfs(const int& N, const int& r, const int& g, const int& b) {
	
	if (r + g + b < N+1 || N+1>=n) return 1;
	if (dp[N][r][g][b]) return dp[N][r][g][b];
	long long sum = 0;
	if (r >= N + 1)
		sum += dfs(N+1, r - (N + 1), g, b);
	if (g >= N + 1)
		sum += dfs(N+1, r , g - (N + 1), b);
	if (b >= N + 1)
		sum += dfs(N+1, r, g , b - (N + 1));
	if ((N + 1) % 3 == 0 && (N + 1) / 3 <= r && (N + 1) / 3 <= g && (N + 1) / 3 <= b)
	{
		long long c = nCr(N + 1, (N + 1) / 3) * nCr(N + 1 -((N + 1) / 3), (N + 1) / 3);
		sum += c*dfs(N+1, r - (N + 1) / 3, g - (N + 1) / 3, b - (N + 1) / 3);
	}
	if ((N + 1) % 2 == 0) {
		if ((N + 1) / 2 <= r && (N + 1) / 2 <= g)
			sum += nCr(N + 1, (N + 1) / 2) * dfs(N+1, r - (N + 1) / 2, g - (N + 1) / 2, b);
		if ((N + 1) / 2 <= b && (N + 1) / 2 <= g)
			sum += nCr(N + 1, (N + 1) / 2) * dfs(N+1, r, g - (N + 1) / 2, b - (N + 1) / 2);
		if ((N + 1) / 2 <= r && (N + 1) / 2 <= b)
			sum += nCr(N + 1, (N + 1) / 2) * dfs(N+1, r - (N + 1) / 2, g  , b - (N + 1) / 2);
	}

	return dp[N][r][g][b] = sum;
}

int main() {
	int r,g,b; std::cin >> n>>r>>g>>b;
	std::cout << dfs(0, r, g, b)<<'\n';

	return 0;
}