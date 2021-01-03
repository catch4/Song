//#include <iostream>
//#include <vector>
//#include <algorithm>
//int main() {
//	int t; std::cin >> t;
//	while (t--) {
//		int n,min_val=0,cnt=1; std::cin >> n;
//		std::vector<std::pair<int,int>> app(n);
//		for (int i = 0; i < n; i++)
//			std::cin >> app[i].first >> app[i].second;
//		sort(app.begin(), app.end());
//		min_val = app[0].second;
//		for (int i = 1; i < n; i++) {
//			if (min_val > app[i].second) {
//				min_val = app[i].second;
//				cnt += 1;
//			}
//		}
//		std::cout << cnt << '\n';
//	}
//
//	return 0;
//}