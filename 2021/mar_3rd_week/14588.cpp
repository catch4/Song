//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define pi std::pair<int,int>
//#define vec2d std::vector<std::vector<int>>
//#define MAX 2147000000
//int n,q;
//
//int main() {
//	std::cin >> n;
//	vec2d mp(n, std::vector<int>(n, MAX));
//	std::vector<pi> vec(n);
//	for (int i = 0; i < n; i++) {
//		std::cin >> vec[i].first >> vec[i].second;
//		mp[i][i] = 0;
//		for (int j = 0; j < i; j++) {
//			if (vec[i].first >= vec[j].first) {
//				if (vec[i].first <= vec[j].second) {
//					mp[i][j] = 1;
//					mp[j][i] = 1;
//				}
//			}
//			else {
//				if (vec[j].first <= vec[i].second) {
//					mp[i][j] = 1;
//					mp[j][i] = 1;
//				}
//			}
//		}
//	}
//	for (int k = 0; k < n; k++)
//		for (int i = 0; i < n; i++)	
//			for (int j = 0; j < n; j++) {
//				if (mp[i][k] == MAX || mp[k][j] == MAX) continue;
//				if (mp[i][j] > mp[i][k] + mp[k][j])
//					mp[i][j] = mp[i][k] + mp[k][j];
//			}
//	std::cin >> q;
//	for (int i = 0; i < q; i++) {
//		int n1, n2; std::cin >> n1 >> n2;
//		if (mp[n1 - 1][n2 - 1] == MAX)
//			std::cout << -1 << '\n';
//		else
//			std::cout << mp[n1 - 1][n2 - 1] << '\n';
//	}
//}