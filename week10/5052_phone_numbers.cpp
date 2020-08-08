/*
Catch study 10주차
백준_전화번호 목록
https://www.acmicpc.net/problem/5052
*/
/*-----------------
풀이
프로그래머스에서 비슷한거 풀어봄

[119, 456, 789,119123] 정렬하면
[119,119123,456,789]식으로 되서 앞뒤만 비교하면됨

-----------------*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
	int t;std::cin>>t;
	while(t--)
	{
		int n;std::cin>>n;
		bool flag=true;
		std::vector<std::string> numbers(n);
		for(int i=0;i<n;i++) std::cin>>numbers[i];
		sort(numbers.begin(),numbers.end());
		for(int i=0;i<n-1;i++){
			if(numbers[i].size()>numbers[i+1].size()) continue;
			else{
				bool flag2=true;
				for(int j=0;j<numbers[i].size();j++)
					if(numbers[i][j]!=numbers[i+1][j]){
						flag2=false;
						break;
					}
				if(flag2)
				{
					flag=false;
					break;
				}
			}
		}
		if(flag)
			std::cout<<"YES\n";
		else
			std::cout<<"NO\n";
	}

	return 0;
}
