#include <iostream>
#include <vector>

int main() {
	int n, k,use=0,cnt=0; std::cin >> n >> k;
	std::vector<int> order(k, 0);
	std::vector<std::vector<int>> remain(k);
	std::vector<bool> ck(k, 0);

	for (int i = 0; i < k; i++) {
		std::cin >> order[i];
		order[i] -= 1;
		remain[order[i]].push_back(i);
	}
	for (int i = 0; i < k; i++)
	{
		if (use < n) {
			if (!ck[order[i]]) {
				ck[order[i]] = 1;
				use += 1;
			}
		}
		else {
			if (!ck[order[i]]) {
				int far_idx=-1,idx=-1;
				for (int j = 0; j < k; j++) {
					if (ck[j]) {
						if (remain[j].size()) {
							if (far_idx < remain[j][0]) {
								far_idx = remain[j][0];
								idx = j;
							}
						}
						else {
							idx = j;
							break;
						}
					}
				}
				ck[idx] = 0;
				ck[order[i]] = 1;
				cnt += 1;
			}
		}
		remain[order[i]].erase(remain[order[i]].begin());
	}
	std::cout << cnt << '\n';
}