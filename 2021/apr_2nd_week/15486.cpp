///*
//Catch study 14/apr/2week
//����_��� 2
//https://www.acmicpc.net/problem/15486
//*/
///*-----------------
//Ǯ��
//�ڿ��� ���� dp,
//��¥ �Ѿ�� �� ��¥ ������ ���� �ؾ�����
//-----------------*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define pi std::pair<int,int>
//int main() {
//	int n; std::cin >> n;
//	std::vector<pi> vec(n);
//	std::vector<int> dp(n+1);
//	for (int i = 0; i < n; i++) std::cin >> vec[i].first >> vec[i].second;
//	for (int i = n - 1; i >= 0; i--) {
//		if (i + vec[i].first > n) {
//			dp[i] = dp[i+1];
//			continue;
//		}
//		dp[i] = std::max(dp[i + 1], dp[i + vec[i].first] + vec[i].second);
//	}
//	
//	std::cout << dp[0] << '\n';
//	return 0;
//}