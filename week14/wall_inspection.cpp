/*
Catch study 14주차
프로그래머스_외벽 점검
https://programmers.co.kr/learn/courses/30/lessons/60062
*/
/*-----------------
풀이
완전 탐색...
-----------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147000000
using namespace std;

int n, m, answer = INF;

void dfs(vector<int>& n_weak, vector<int>& dist, vector<bool>& ck,
	const int& res, const int& cnt)
{
	if (cnt>answer) return;
	if (!res) answer = std::min(answer, cnt);
	else if (res&&cnt == dist.size()) return;
	else {
		for (int i = 0; i < m; i++) {
			if (!ck[i])
			{
				int n_res = res, j;
				for (j = i; j - i < m&&n_weak[j] - n_weak[i] <= dist[cnt] && !ck[j%m]; j++)
				{
					ck[j%m] = 1; // 고친 배열 체크
					n_res -= 1;
				}
				dfs(n_weak, dist, ck, n_res, cnt + 1);
				for (int k = i; k<j; k++)
					ck[k%m] = 0;
			}
		}
	}
}

int solution(int N, vector<int> weak, vector<int> dist) {
	n = N;
	m = weak.size();
	int res = m;
	std::vector<int> n_weak;
	vector<bool> ck(m, 0);

	for (int i = 0; i < m; i++) n_weak.push_back(weak[i]);
	for (int i = 0; i < m; i++) n_weak.push_back(weak[i] + n); // 시계방향으로만 계산하려고 오른쪽에 추가

	sort(dist.rbegin(), dist.rend()); // 큰 순서로 정렬
	dfs(n_weak, dist, ck, res, 0);
	if (answer == INF) return -1;
	return answer;
}

int main(){
	int N=12;
	std::vector<int> weak,dist;
	
	//1.
	/*weak.push_back(1);
	weak.push_back(5);
	weak.push_back(6);
	weak.push_back(10);

	dist.push_back(1);
	dist.push_back(2);
	dist.push_back(3);
	dist.push_back(4);*/
	
	//2.
	weak.push_back(1);
	weak.push_back(3);
    weak.push_back(4);
    weak.push_back(9);
    weak.push_back(10);

    dist.push_back(3);
    dist.push_back(5);
    dist.push_back(7);
	
	//3.
	/*weak.push_back(0);
	weak.push_back(10);
	weak.push_back(50);
	weak.push_back(80);
	weak.push_back(120);
	weak.push_back(160);

	dist.push_back(1);
	dist.push_back(10);
	dist.push_back(5);
	dist.push_back(40);
	dist.push_back(30);*/

	std::cout<<solution(N,weak,dist);
}
