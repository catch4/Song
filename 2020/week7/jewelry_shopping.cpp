/*
Catch study 7주차
프로그래머스_보석 쇼핑
https://programmers.co.kr/learn/courses/30/lessons/67258
*/
/*-------------------------
풀이
조건 만족할 때 가장 작은 배열 최신화 함.

1. init 함수에서는 가장 처음 조건을 만족하는 배열을 찾음
	1.1 처음 보는 문자열일 경우 set이라는 vector에 추가
	    그리고 현재까지 나온 배열(1.2에서 count한거)로 카운트 최신화
	1.2 처음 나온 문자열 아닐 경우 cont

2. init 함수에서 구한 최초 완성 배열로 시작, 여기서 최소 찾음
	2.1 배열의 첫 문자열이 1개만 남은 경우 오른쪽에서 같은 문자열 찾음,
	    이 과정에서 나온 문자열 싹다 +
	2.2 gems array 끝까지 조건 만족하는게 더이상 없을 경우 함수 종료
	2.3 배열의 첫 문자열이 1개 이상인 경우 카운트 -
	2.4 (2.1,2.3) 공통으로 현재 왼쪽 시작지점을 +1 해도 되므로 이거 기준으로 최소길이 확인,
		최소 길이일 경우 배열 시작,끝 지점 최신화
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

