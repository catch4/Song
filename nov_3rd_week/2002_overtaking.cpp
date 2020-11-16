#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
int main() {
	int cnt = 0,n; std::cin >> n;
	std::unordered_map<std::string, int> mp;
	std::vector<std::string> out(n);
	for (int i = 0; i < n; i++) {
		std::string in; std::cin >> in;
		mp[in] = i+1;
	}
	
	for (int i = 0; i < n; i++)
		std::cin >> out[i];
	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (mp[out[i]] > mp[out[j]])
			{
				cnt += 1;
				break;
			}
	std::cout << cnt << '\n';

	return 0;
}