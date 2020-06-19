/*
Catch study 3����
����_7453 ���� 0�� �� ����
https://www.acmicpc.net/problem/7453
*/
/*
A+B�� ���� ����, sort�ϰ� -(C+D)�� ���� �� ã��

sotring�� �߱� ������ upper_bound�� lower_bound
�Լ��� ����� ������ return ���� ���ִ�.
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





// �ٸ� ��� �ڵ� - ������ ���� hash�� �����ϸ� sorting�� ���� �ʾƵ� �ȴ�.
//#include <iostream>
//
//#define HASHLIMIT (1 << 24) 1024^2 * 4^2
//#define STEP 2317 -> ���� �������� �𸣰���
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