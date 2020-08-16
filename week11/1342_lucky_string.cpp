/*
Catch study 11주차
백준_행운의 문자열
https://www.acmicpc.net/problem/1342
*/
/*-----------------
풀이
맨처음에는 unorderd_map써서 string 체크 했었는데
시간초과 나서 문자별로 카운트하고 브루트포스함
-----------------*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int n;
std::string str;
std::vector<char> chs; // 문자
std::vector<int> cnts; // 문자별 카운트수

int dfs(const char& ch,const int& now)
{
	if(now==n){
		return 1;
	}
	else{
		int sum=0;
		for(int i=0;i<chs.size();i++){
			if(cnts[i]){
				if(!now||ch!=chs[i])
				{
					cnts[i]-=1;
					sum+=dfs(chs[i],now+1);
					cnts[i]+=1;
				}
			}
		}
		return sum;
	}
}

int main(){
	std::cin>>str;
	n=str.size();
	sort(str.begin(),str.end());
	int cnt=0;
	char ch=str[0];
	for(int i=0;i<n+1;i++)
	{
		if((i==n&&cnt)||ch!=str[i])
		{
			chs.push_back(ch);
			cnts.push_back(cnt);
			cnt=1;
			ch=str[i];
		}
		else cnt+=1;
	}

	std::cout<<dfs(0,0);
}

