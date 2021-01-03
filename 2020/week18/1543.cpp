#include <iostream>
#include <string>
#include <vector>

std::vector<int> getpi(std::string& b) {
	int j = 0;
	std::vector<int> pi(b.size());
	for (int i = 1; i < b.size(); i++) {
		while (j > 0 && b[i] != b[j]) j = pi[j - 1];
		if (b[i] == b[j]) pi[i] = ++j;
	}
	return pi;
}

int kmp(std::string& a, std::string& b) {
	std::vector<int> ret;
	std::vector<int> pi = getpi(b);
	int j = 0, answer = 0;
	for (int i = 0; i < a.size(); i++)
	{
		while (j > 0 && a[i] != b[j]) j = pi[j - 1];
		if (a[i] == b[j]) {
			if (j == b.size() - 1) {
				answer+=1;
				j = 0;
			}
			else j+=1;
		}
	}
	return answer;
}

int main() {
	std::string a, b;
	std::getline(std::cin, a);
	std::getline(std::cin, b);
	std::cout << kmp(a, b) << '\n';
}