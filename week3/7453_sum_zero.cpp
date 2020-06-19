/*
Catch study 3주차
백준_7453 합이 0인 네 정수
https://www.acmicpc.net/problem/7453
*/
/*
A+B의 합을 저장, sort하고 -(C+D)와 같은 거 찾기

sotring을 했기 때문에 upper_bound와 lower_bound
함수를 사용해 개수를 return 받을 수있다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n; long long cnt = 0;	std::cin >> n;
	std::vector<int> A(n), B(n), C(n), D(n);
	std::vector<long long> vec;
	for (int i = 0; i < n; i++) std::cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			vec.push_back(A[i] + B[j]);

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			long long sum = (C[i] + D[j])*-1;
			cnt += std::upper_bound(vec.begin(), vec.end(), sum) - std::lower_bound(vec.begin(), vec.end(), sum);
		}
	}
	std::cout << cnt << std::endl;
	return 0;
}





// 다른 사람 코드 - 다음과 같이 hash로 구현하면 sorting을 하지 않아도 된다.
//#include <iostream>
//
//#define HASHLIMIT (1 << 24) 1024^2 * 4^2
//#define STEP 2317 -> 무슨 기준인지 모르겠음
//
//using namespace std;
//using uint = unsigned int;
//using ll = long long;
//
//int N;
//int a[4001], b[4001], c[4001], d[4001];
//
//struct HASH {
//	int realnum;
//	int cnt;
//};
//
//HASH hashtable[HASHLIMIT];
//
//void save_hash(uint num) {
//	uint key = num % HASHLIMIT;
//
//	while (hashtable[key].cnt) {
//		if (hashtable[key].realnum == num) {
//			hashtable[key].cnt++;
//			return;
//		}
//		key = (key + STEP) % HASHLIMIT;
//	}
//
//	hashtable[key].realnum = num;
//	hashtable[key].cnt = 1;
//}
//
//ll find_hash(uint num) {
//	uint key = num % HASHLIMIT;
//
//	while (hashtable[key].cnt) {
//		if (hashtable[key].realnum == num)
//			return hashtable[key].cnt;
//		key = (key + STEP) % HASHLIMIT;
//	}
//	return 0;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int i, j;
//	ll ans = 0;
//	cin >> N;
//	for (i = 0; i < N; i++) {
//		cin >> a[i] >> b[i] >> c[i] >> d[i];
//	}
//
//	for (i = 0; i < N; i++) {
//		for (j = 0; j < N; j++) {
//			save_hash(c[i] + d[j]);
//		}
//	}
//	for (i = 0; i < N; i++) {
//		for (j = 0; j < N; j++) {
//			ans += find_hash((uint)(-(a[i] + b[j])));
//		}
//	}
//	cout << ans << "\n";
//}