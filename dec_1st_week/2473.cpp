#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, ret[3] = { 0, }; std::cin >> n;
	long long  min = 214700000000;
	std::vector<long long> vec(n);
	for (int i = 0; i < n; i++)
		std::cin >> vec[i];

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n - 2; i++)
	{
		int l = i + 1, r = n - 1;
		while (l < r) {
			long long  sum = vec[i] + vec[l] + vec[r];
			//std::cout << sum<<" "<<min << '\n';
			if (min > abs(sum)) {
				min = abs(sum);
				ret[0] = vec[i];
				ret[1] = vec[l];
				ret[2] = vec[r];
			}

			if (sum < 0) l += 1;
			else if (sum > 0) r -= 1;
			else {
				i = n - 2;
				break;
			}
		}
	}

	for (int i = 0; i < 3; i++)
		std::cout << ret[i] << " ";

	return 0;
}