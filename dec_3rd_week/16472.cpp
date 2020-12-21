#include <iostream>
#include <string>
#include <vector>

struct Info {
	int cnt[26] = { 0, }, lowers = 0;
	void add(char c) {
		int idx = c - 'a';
		if (!cnt[idx]) lowers+=1;
		cnt[idx] += 1;
	}
	void del(char c) {
		int idx = c - 'a';
		cnt[idx] -= 1;
		if (!cnt[idx]) lowers -= 1;
	}
};

int main() {
	int n,max=0;
	std::string str;
	std::cin >> n >> str;
	int l=0, r=0;
	Info info;
	while (r < str.size()) {
		while (info.lowers <= n&&r<str.size()) {
			info.add(str[r]);
			r += 1;
			if (info.lowers<=n && r - l > max) {
				max = r - l;
			}			
		}
		while (info.lowers > n)
		{
			info.del(str[l]);
			l+=1;
		}
	}
	std::cout << max << '\n';
}