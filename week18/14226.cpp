#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int dst;
	std::cin >> dst;
	std::vector<int> vec(dst + 1);
	for (int i = 2; i <= dst; i++) vec[i] = i;
	for (int i = 2; i <= dst; i++) {			
		int t = vec[i] + 1;
		for (int j = i; j <= dst; j += i) {
			vec[j] = std::min(t,vec[j]);
			t++;
		}
		for (int j = dst - 1; j >= 2; j--) {
			vec[j] = std::min(vec[j], vec[j + 1] + 1);
		}
	}

	std::cout << vec[dst] << '\n';
	
	return 0;
}
