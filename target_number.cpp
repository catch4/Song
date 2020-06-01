#include <iostream>
#include <vector>

using namespace std;

void DFS(std::vector<int> numbers, int& answer,int sum,int now,const int& target)
{
	if (now == numbers.size())
	{
		if (sum == target) answer++; // 합이 목표와 동일할 경우 answer++
	}
	else
	{
		DFS(numbers, answer, sum + numbers[now], now + 1, target);
		DFS(numbers, answer, sum - numbers[now], now + 1, target);
	}
}


int solution(std::vector<int> numbers, int target) {
	int answer = 0;
	DFS(numbers, answer, 0, 0, target);
	return answer;
}

// input ex)
// 5 3 1 1 1 1 1 

int main() {
	int n, target;
	std::cin >> n >> target;
	std::vector<int> numbers(n);
	for (int i = 0; i < n; i++) std::cin >> numbers[i];

	std::cout << solution(numbers, target) << std::endl;
}