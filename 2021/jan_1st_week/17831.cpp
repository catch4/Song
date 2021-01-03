/*
Catch study 21/jan/1week
����_���� �¹��̳�
https://www.acmicpc.net/problem/17831
*/
/*-----------------
Ǯ��
dfs + dp�� Ǯ��. īī�� 2021 ����ε� 7���� �����ϰ� ǰ

���� ��
(first) ���� �ڽ��� ����(p)�� �ڽ��� ��Ī�� ����� �ִ밪
	- �������� �޾ƿ� ���ϰ� second �� �� ��(total) + �ڽŰ� ������ ��(people[p] * people[c])
	
(second) �ڽ��� ����(p)�� ��Ī �ȵ� ����� �ִ밪 ����
	�Ʒ��� �� ū ��
	- �������� �޾ƿ� ���ϰ� second�� �� ��(total)
	- Ư�� ������ ��Ī �Ǿ��� ���� ��(ret[i].first) + ������ �������� ��Ī �ȵǾ��� ���� �� (total-ret[i].second)

���� ���
	- �ֻ��� ���� ��Ī�� ������ �����Ƿ� second ���
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