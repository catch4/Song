/*
Catch study 1주차
프로그래머스_추석 트래픽
https://programmers.co.kr/learn/courses/30/lessons/17676
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// h,m,s,ms 정수형태로 변환
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
		int cnt = 1,end = sh[i].second+1000; // 해당 로그가 포함되는 1초 범위
		for (int j = i + 1; j <len;j++)
		{
			// 무조건 sh[j].second > sh[i].second 이므로 확인할 필요 X
			// 시작범위만 확인
			if (sh[j].first < end) cnt++; 
		}
		if (cnt > answer) answer = cnt;
	}
	return answer;
}

