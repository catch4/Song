/*
Catch study 5����
���α׷��ӽ�_������
https://programmers.co.kr/learn/courses/30/lessons/42629
*/
/*---------------------------
Ǯ��
�켱���� ť�� Ǯ��

��¥�� �ɶ� Q�� �ְ� 
0�̸��� �� ���� ū �� ���� �޴´�.
---------------------------*/
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	std::priority_queue<int> Q;
	int day = 0,cur=0;
	int answer = 0;
	while (day<k)
	{
		stock -= 1;
		if (day == dates[cur]) {
			Q.push(supplies[cur]);
			if(cur<dates.size()-1)
				cur += 1;
		}
		if (stock < 0)
		{
			stock += Q.top();
			Q.pop();
			answer += 1;
		}
		day++;
	}
	
	return answer;
}


/*
4
3
4 10 15
20 5 10
30

*/

int main() {
	int stock, n, k;
	std::cin >> stock >> n;
	std::vector<int> dates(n), supplies(n);
	for (int i = 0; i < n; i++) std::cin >> dates[i];
	for (int i = 0; i < n; i++) std::cin >> supplies[i];
	std::cin >> k;
	std::cout << solution(stock, dates, supplies, k);
}