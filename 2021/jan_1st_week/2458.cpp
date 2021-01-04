//#include <iostream>
//#include <vector>
//
//int n, m;
//struct Info {
//	std::vector<int> b, s;
//};
//
//int search(std::vector<Info>& student, std::vector<bool>& ck, const int& idx,const bool& is_big) {
//	int ret = 1;
//	ck[idx] = 1;
//	if (is_big) {
//		for (int i = 0; i < student[idx].b.size(); i++)
//			if (!ck[student[idx].b[i]])
//				ret += search(student, ck, student[idx].b[i], is_big);
//	}
//	else {
//		for (int i = 0; i < student[idx].s.size(); i++)
//			if (!ck[student[idx].s[i]])
//				ret += search(student, ck, student[idx].s[i], is_big);
//	}
//	return ret;
//}
//
//int main() {
//	int answer = 0;
//	std::cin >> n >> m;
//	std::vector<Info> student(n);
//
//	for (int i = 0; i < m; i++)
//	{
//		int big, small; std::cin >> small >> big;
//		student[big - 1].s.push_back(small - 1);
//		student[small - 1].b.push_back(big - 1);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		std::vector<bool> ck(n);
//		int big = search(student, ck, i, true)-1;
//		int small = search(student, ck, i, false) - 1;
//		if (big + small == n - 1) answer += 1;
//	}
//
//	std::cout << answer << '\n';
//}