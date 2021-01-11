#include <iostream>
#include <vector>
int n;
bool solve(std::vector<int>& vec, const int& idx, const int& a, const int& b) {
	if (idx > n - 1) return true;
	if (vec[idx] == vec[idx - 1] * a + b) {
		if (idx == n - 1) return true;
		else
			return solve(vec, idx + 1, a, b);
	}
	else
		return false;
}

int main() {
	std::cin >> n;
	int answer = 0,cnt=0;
	std::vector<int> vec(n);
	for (int i = 0; i < n; i++) std::cin >> vec[i];
	
	for (int i = -100000; i<1000000; i++) {
		int b = vec[1] - (vec[0] * i);
		if (solve(vec, 2, i, b)){
			if (abs(answer) <= 100) {
				if (cnt) {
					if (answer != vec[n - 1] * i + b) {
						cnt += 1;
						break;
					}
				}
				else {
					answer = vec[n - 1] * i + b;
					cnt = 1;
				}
			}
		}		
	}
	if (cnt > 1) {
		std::cout << 'A';
	}
	else if (cnt)
		std::cout << answer;
	else
		std::cout << 'B';
}