/*
Catch study 7����
���α׷��ӽ�_���� ����
https://programmers.co.kr/learn/courses/30/lessons/67258
*/
/*-------------------------
Ǯ��
���� ������ �� ���� ���� �迭 �ֽ�ȭ ��.

1. init �Լ������� ���� ó�� ������ �����ϴ� �迭�� ã��
	1.1 ó�� ���� ���ڿ��� ��� set�̶�� vector�� �߰�
	    �׸��� ������� ���� �迭(1.2���� count�Ѱ�)�� ī��Ʈ �ֽ�ȭ
	1.2 ó�� ���� ���ڿ� �ƴ� ��� cont

2. init �Լ����� ���� ���� �ϼ� �迭�� ����, ���⼭ �ּ� ã��
	2.1 �迭�� ù ���ڿ��� 1���� ���� ��� �����ʿ��� ���� ���ڿ� ã��,
	    �� �������� ���� ���ڿ� �ϴ� +
	2.2 gems array ������ ���� �����ϴ°� ���̻� ���� ��� �Լ� ����
	2.3 �迭�� ù ���ڿ��� 1�� �̻��� ��� ī��Ʈ -
	2.4 (2.1,2.3) �������� ���� ���� ���������� +1 �ص� �ǹǷ� �̰� �������� �ּұ��� Ȯ��,
		�ּ� ������ ��� �迭 ����,�� ���� �ֽ�ȭ
---------------------------*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int min_len;

// 2.
void Move(vector<string>& gems, std::vector<string>& set, std::vector<int>& str_cnt,
	std::pair<int, int>& pi)
{
	std::pair<int, int> tmp = pi;
	while (tmp.second < int(gems.size())) {
		int idx =std::find(set.begin(), set.end(), gems[tmp.first])-set.begin();
		if (str_cnt[idx] == 1) { // 2.1
			tmp.second += 1;
			while (tmp.second < int(gems.size()) && gems[tmp.first] != gems[tmp.second]) {
				str_cnt[std::find(set.begin(), set.end(), gems[tmp.second]) - set.begin()]+=1;
				tmp.second += 1;
			}
			if (tmp.second == gems.size() && gems[tmp.first] != gems[tmp.second - 1]) return; // 2.2
		}
		else
			str_cnt[idx] -= 1; // 2.3
		tmp.first += 1; // 2.4
		if (tmp.second - tmp.first+1 < min_len) {
			min_len = tmp.second - tmp.first+1;
			pi = tmp;
		}
	}
}

// 1.
void Init(vector<string>& gems, std::vector<string>& set, std::vector<int>& str_cnt
	,std::pair<int, int>& pi) {
	std::vector<int> tmp_cnt;
	pi.first = 0;
	for (int i = 0; i <int(gems.size()); i++)
	{
		auto iter = find(set.begin(),set.end(),gems[i]);
		if (iter == set.end()) // 1.1
		{
			tmp_cnt.push_back(1);
			str_cnt = tmp_cnt;
			set.push_back(gems[i]);
			pi.second = i;
		}
		else tmp_cnt[iter - set.begin()] += 1; // 1.2
	}
	min_len = pi.second - pi.first + 1;
}

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	std::vector<int> str_cnt;
	std::vector<string> set;
	std::pair<int, int> pi;
	Init(gems, set, str_cnt, pi);
	Move(gems, set, str_cnt, pi);
	answer.push_back(pi.first+1);
	answer.push_back(pi.second+1);
	return answer;
}
int main() {
	std::vector<string> gems;
	
	//gems.push_back("DIA");
	//gems.push_back("RUBY");
	//gems.push_back("RUBY");
	//gems.push_back("DIA");
	//gems.push_back("DIA");
	//gems.push_back("EMERALD");
	//gems.push_back("SAPPHIRE");
	//gems.push_back("DIA");
	

	
	/*gems.push_back("AA");
	gems.push_back("AB");
	gems.push_back("AC");
	gems.push_back("AA");
	gems.push_back("AC");*/
	

	
	//gems.push_back("XYZ");
	//gems.push_back("XYZ");
	//gems.push_back("XYZ"); 
	

	
	//gems.push_back("ZZZ");
	//gems.push_back("YYY");
	//gems.push_back("NNNN");
	//gems.push_back("YYY");
	//gems.push_back("BBB");

	gems.push_back("DIA");
	gems.push_back("DIA");
	gems.push_back("RUBY");
	gems.push_back("RUBY");
	gems.push_back("SAPPHIRE");
	gems.push_back("EMERALD");
	gems.push_back("DIA");
	gems.push_back("RUBY");
	gems.push_back("SAPPHIRE");
	gems.push_back("EMERALD");
	gems.push_back("DIA");
	gems.push_back("SAPPHIRE");
	gems.push_back("SAPPHIRE");
	gems.push_back("RUBY");

	std::vector<int> answer = solution(gems);
	std::cout << answer[0] << " " << answer[1];
}

