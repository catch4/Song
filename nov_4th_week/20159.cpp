// ´©ÀûÇÕ
// https://www.acmicpc.net/problem/20159
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n,answer=0; std::cin >> n;
	std::vector<int> vec1(n/2+1,0);
	std::vector<int> vec2(n/2+1, 0);

	for (int i = 1; i < n / 2+1; i++)
	{
		std::cin >> vec1[i] >> vec2[i];
		vec1[i] += vec1[i - 1];
		vec2[i] += vec2[i - 1];
	}
	answer = vec1[n / 2];
	
	for (int i = 1; i < n / 2+1; i++) {
		int case1 = vec2[n/2-1] - vec2[i - 1] + vec1[i]; // »óÅÂÅÏ¿¡ ¹ØÀå»©±â
		int case2 = vec1[i - 1] + vec2[n / 2] - vec2[i-1]; // ³»ÅÏ¿¡ ¹ØÀå»©±â
		answer = std::max(std::max(answer, case1), case2);
	}
	std::cout << answer << '\n';
	return 0;
}