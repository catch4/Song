//#include <iostream>
//#include <vector>
//#include <algorithm>
//struct C {
//	int e1, e2, c;
//	bool operator<(const C& bb)
//	{
//		return c < bb.c;
//	}
//};
//
//int find(std::vector<int>& p ,const int& num) {
//	if (p[num] == num) return num;
//	else return p[num] = find(p, p[num]);
//}
//
//int main() {
//	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
//	int n, m,cnt=0,answer=0; std::cin >> n >> m;
//	std::vector<int> p(n);
//	std::vector<C> cc(m);
//	for (int i = 0; i < n; i++) p[i] = i;
//	for (int i = 0; i < m; i++) {
//		std::cin >> cc[i].e1 >> cc[i].e2 >> cc[i].c;
//		cc[i].e1 -= 1;
//		cc[i].e2 -= 1;
//	}
//	sort(cc.begin(), cc.end());
//	for (int i = 0; i < m && cnt<n-2; i++)
//	{
//		int p1 = find(p,cc[i].e1),p2 = find(p,cc[i].e2);
//		if (p1 != p2) {
//			answer += cc[i].c;
//			p[std::max(p1, p2)] = std::min(p1, p2);
//			cnt++;
//		}
//	}
//	
//	std::cout << answer << '\n';
//	return 0;
//}