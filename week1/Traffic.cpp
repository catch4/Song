/*
Catch study 1����
���α׷��ӽ�_�߼� Ʈ����
https://programmers.co.kr/learn/courses/30/lessons/17676
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// h,m,s,ms �������·� ��ȯ
pair<int,int> to_num(string& str)
{
	pair<int, int> ret;
	int sum = 0,start_sum=0,unit=1000;
	sum += ((str[11] - '0') * 10 + (str[12] - '0'))*3600;
	sum += ((str[14] - '0') * 10 + (str[15] - '0')) * 60;
	sum += (str[17] - '0') * 10 + (str[18] - '0');
	sum *= 1000;
	sum += ((str[20] - '0') * 100 + (str[21] - '0') * 10 + (str[22] - '0'));
	
	for (int i = 24;; i++)
	{
		if (str[i] == '.') continue;
		if (str[i] == 's') return { sum - start_sum + 1,sum};
		start_sum += (str[i] - '0')*unit;
		unit /= 10;
	}
}

int solution(vector<string> lines) {
	int answer = 0, len = lines.size();
	vector<pair<int, int>> sh(len);
	for (int i = 0; i < len; i++) sh[i] = to_num(lines[i]);
	for (int i = 0; i <len; i++)
	{
		int cnt = 1,end = sh[i].second+1000; // �ش� �αװ� ���ԵǴ� 1�� ����
		for (int j = i + 1; j <len;j++)
		{
			// ������ sh[j].second > sh[i].second �̹Ƿ� Ȯ���� �ʿ� X
			// ���۹����� Ȯ��
			if (sh[j].first < end) cnt++; 
		}
		if (cnt > answer) answer = cnt;
	}
	return answer;
}

