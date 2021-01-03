/*
Catch study 2주차
백준_2352 반도체 설계
https://www.acmicpc.net/problem/2352
*/

/*
풀이
최대 배열길이가 40000이고, 시간제한 2초라서 O(n)에 가깝게 구현하려고 함.
=> 다이나믹 프로그래밍
현재 연결된 개수를 index로 하고 각 index에 최소 숫자를 할당.
index가 작을 수록 O(n)에 가까움, index가 크더라도 조건 만족시
바로 탈출하기 때문에 O(n2)보다 작음

0. 연결횟수 = index, index값 = 최소 숫자 를 만족하는 배열 선언(chain)
1. chain의 index가 큰 것 부터 비교
	1-1. 현재 숫자가 chain의 최대 index보다 클 때는 push_back
	1-2. 현재 숫자가 chain의 현재 index보다 클 경우 index+1 위치의
	     값과 비교해 최소값 할당
2. chain의 첫 index는 0이기 때문에 -1

*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n; std::cin >> n;
	int max_idx = 0;
	std::vector<int> nums(n);
	for (int i = 0; i < n; i++)
		std::cin >> nums[i];
	std::vector<int> chain; // 0.
	chain.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int len = chain.size();
		for(int j=len-1;j>=0;j--)
			if (chain[j] < nums[i])
			{
				if (j == len - 1)
					chain.push_back(nums[i]); // 1-1.
				else
					chain[j + 1] = std::min(chain[j + 1], nums[i]); // 1-2.
				break;
			}
	}
	
	std::cout << chain.size() - 1 << std::endl; // 2.
}