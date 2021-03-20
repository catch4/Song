/*
Catch study 17/mar/3week
백준_20366 같이 눈사람 만들래?
https://www.acmicpc.net/problem/20366

정렬 후 한 눈사람 고정 이후 투포인터
*/
#include <iostream>
#include <algorithm>
#include <vector>
int n,answer=2147000000;

int main() {
	std::cin >> n;
	std::vector<int> vec(n);
	for (int i = 0; i < n; i++) std::cin >> vec[i];
	sort(vec.begin(), vec.end());
	for (int l1=0;l1<n-1;l1++)
		for (int r1 = l1 + 1; r1 < n ; r1++) {
			int l2 = 0,r2=n-1,sum1=vec[l1]+vec[r1];

			while (l2 < r2) {
				while (l2 == l1 || l2 == r1) l2 += 1;
				while (r2 == l1 || r2 == r1) r2 -= 1;
				if (l2 >= r2) break;
				int sum2 = vec[l2] + vec[r2];
				answer = std::min(answer, abs(sum1 - sum2));
				
				if (sum1 < sum2)
					r2 -= 1;
				else
					l2 += 1;

			}
		}
	std::cout << answer << '\n';
	return 0;
}
/*
Catch study 17/mar/3week
백준_20366 같이 눈사람 만들래?
https://www.acmicpc.net/problem/20366

[다른 코드 참고]
sum으로 sort후 겹치는 element 없을 경우 값 최신화
*/
#include <iostream>
#include <vector>
#include <algorithm>

int n,answer = 2147000000;

struct Sum {
	int s, i, j;
	bool operator<(const Sum& b) { return s < b.s; }
	bool operator!=(const Sum& b) { 
		return i!=b.i && i!=b.j && j!=b.i && j!=b.j; }
};

int main() {
	std::cin >> n;
	std::vector<int> num(n);
	std::vector<Sum> sums;
	for (int i = 0; i < n; i++) std::cin >> num[i];
	for (int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			sums.push_back({ num[i] + num[j],i,j });
	sort(sums.begin(), sums.end());
	for (int i = 1; i < sums.size(); i++)
		if (sums[i] != sums[i - 1]) answer=std::min(answer, sums[i].s - sums[i-1].s);
	std::cout << answer;
	return 0;
}