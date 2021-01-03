/*
Catch study 21/jan/1week
백준_대기업 승범이네
https://www.acmicpc.net/problem/17831
*/
/*-----------------
풀이
dfs + dp로 풀이. 카카오 2021 블라인드 7번과 유사하게 품

리턴 값
(first) 현재 자신의 멘토(p)와 자신이 매칭된 경우의 최대값
	- 하위에서 받아온 리턴값 second 의 총 합(total) + 자신과 멘토의 곱(people[p] * people[c])
	
(second) 자신이 멘토(p)와 매칭 안될 경우의 최대값 리턴
	아래중 더 큰 값
	- 하위에서 받아온 리턴값 second의 총 합(total)
	- 특정 하위와 매칭 되었을 때의 값(ret[i].first) + 나머지 하위에서 매칭 안되었을 때의 값 (total-ret[i].second)

최종 출력
	- 최상위 노드는 매칭될 상위가 없으므로 second 출력
-----------------*/

#include <iostream>
#include <vector>
#define vec2d std::vector<std::vector<int>>
#define pi std::pair<int,int>
int n;

pi synergy(std::vector<int>& people, vec2d& mentee,const int& p,const int& c) {
	if (mentee[c].size())
	{
		int total = 0,not_choice=0,choice=0;
		std::vector<pi> ret(mentee[c].size());
		for (int i = 0; i < mentee[c].size(); i++)
		{
			ret[i] = synergy(people, mentee, c, mentee[c][i]);
			total += ret[i].second;
		}
		not_choice = total;
		for (int i = 0; i < mentee[c].size(); i++)
			if (not_choice < total - ret[i].second + ret[i].first)
				not_choice = total - ret[i].second + ret[i].first;
		choice = people[p] * people[c] + total;
		return{ choice,not_choice };
	}
	else
		return { people[p] * people[c], 0 };
}

int main() {
	std::cin >> n;
	std::vector<int> people(n);
	vec2d mentee(n);
	for (int i = 1; i < n; i++) {
		int mentor; std::cin >> mentor;
		mentee[mentor - 1].push_back(i);
	}
	for (int i = 0; i < n; i++) std::cin >> people[i];
	std::cout << synergy(people, mentee, 0, 0).second<<'\n';
	return 0;
}