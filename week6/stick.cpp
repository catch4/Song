///*
//Catch study 6주차
//프로그래머스_조이스틱
//https://programmers.co.kr/learn/courses/30/lessons/42860
//*/
//
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int solution(string name) {
//	int answer = 0,right=0,left=0;
//	std::vector<int> vec(name.size());
//	for (int i = 0; i < name.size(); i++) {
//		vec[i] = name[i] - 'A' < 'Z' - name[i] + 1 ? name[i] - 'A' : 'Z' - name[i] + 1;
//		answer += vec[i];
//	}
//	answer += name.size() - 1;
//	for (int i = 1; i < name.size(); i++)
//	{
//		if (!vec[i]) right++;
//		else break;
//	}
//	for (int i = name.size() - 1; i >= 1; i--)
//	{
//		if (!vec[i]) left++;
//		else break;
//	}
//	
//	int l_cur, r_cur, max = left>right? left:right;
//	for (l_cur = 1; l_cur<name.size()&&vec[l_cur] != 0; l_cur++) {}
//	for (r_cur = name.size() - 1; r_cur >= 0&&vec[r_cur] != 0; r_cur--) {}
//	if (l_cur-1 < r_cur+1)
//	{
//		l_cur -= 1;
//		r_cur += 1;
//		int cnt = 0;
//		for (int i = l_cur+1; i < r_cur; i++)
//			if(!vec[i])cnt++;
//			else break;
//		int diff = r_cur - l_cur-1;
//		r_cur = name.size() - r_cur;
//		int min = l_cur < r_cur ? l_cur : r_cur;
//		if (diff==cnt&&diff - min > max) return answer - diff + min;
//		else return answer - max;
//	}
//	else return answer - max;
//}
