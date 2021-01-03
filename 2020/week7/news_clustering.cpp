#include <string>
#include <iostream>
#include <map>
#define pi std::pair<int,int>
using namespace std;

int solution(string str1, string str2) {
	int answer = 0,cnt =0;
	int len1 = str1.size() - 1, len2 = str2.size() - 1;
	std::map<pi,int> map;
	for (int i = 0; i < str1.size() - 1; i++)
	{
		if (!((str1[i] <= 'z'&&str1[i] >= 'a') || (str1[i] <= 'Z'&&str1[i] >= 'A'))||
			!((str1[i + 1] <= 'z'&&str1[i + 1] >= 'a') || (str1[i + 1] <= 'Z'&&str1[i+1] >= 'A')))
			len1 -= 1;
		else if (str1[i] <= 'z'&&str1[i] >= 'a') {
			if (str1[i + 1] <= 'z'&&str1[i + 1] >= 'a') map[{str1[i] - 'a', str1[i + 1] - 'a'}] += 1;
			else map[{str1[i] - 'a', str1[i + 1] - 'A'}] += 1;
		}
		else {
			if (str1[i + 1] <= 'z'&&str1[i + 1] >= 'a') map[{str1[i] - 'A', str1[i + 1] - 'a'}] += 1;
			else map[{str1[i] - 'A',str1[i + 1] - 'A'}] += 1;
		}
	}
	
	for (int i = 0; i < str2.size() - 1; i++)
	{
		if (!((str2[i] <= 'z'&&str2[i] >= 'a') || (str2[i] <= 'Z'&&str2[i] >= 'A'))||
			!((str2[i+1] <= 'z'&&str2[i+1] >= 'a') || (str2[i+1] <= 'Z'&&str2[i+1] >= 'A')))
			len2 -= 1;
		else if (str2[i] <= 'z'&&str2[i] >= 'a') {
			if (str2[i + 1] <= 'z'&&str2[i + 1] >= 'a') {
				if (map[{str2[i] - 'a', str2[i + 1] - 'a'}])
				{
					cnt += 1;
					map[{str2[i] - 'a', str2[i + 1] - 'a'}] -= 1;
				}
			}
			else {
				if (map[{str2[i] - 'a', str2[i + 1] - 'A'}])
				{
					cnt += 1;
					map[{str2[i] - 'a', str2[i + 1] - 'A'}] -= 1;
				}
			}
		}
		else {
			if (str2[i + 1] <= 'z'&&str2[i + 1] >= 'a')
			{
				if (map[{str2[i] - 'A', str2[i + 1] - 'a'}]) {
					cnt += 1;
					map[{str2[i] - 'A', str2[i + 1] - 'a'}] -= 1;
				}
			}
			else {
				if (map[{str2[i] - 'A', str2[i + 1] - 'A'}])
				{
					cnt += 1;
					map[{str2[i] - 'A', str2[i + 1] - 'A'}] -= 1;
				}
			}
		}
	}

	
	if (!cnt) return 65536;
	else {
		double bot = ((double)len1 - cnt) + ((double)len2);
		double ret = cnt / bot;
		answer = ret * 65536;
		return answer;
	}
}
