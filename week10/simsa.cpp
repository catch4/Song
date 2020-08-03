/*
 Catch Study 10주차
 프로그래머스_입국심사
 https://programmers.co.kr/learn/courses/30/lessons/43238?language=cpp
 * */
/*-------------------
 이분탐색, 최대값 엄청 늘리면 되는거였음
-------------------- */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(long long n,vector<int>& times,long long mid){
	long long tmp=0;
	for(int i=0;i<times.size();i++){
		tmp+= mid/times[i];
		if(tmp>=n) return true;
	}
	return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 1,l=1,r= 223372036854775807;
    while(l<=r)
    {
	   long long mid = (l+r)/(long long)2;
	   if(check(n,times,mid)){
		   answer=mid;
           r=mid-1;
	   }
	   else{
		   l=mid+1;
	   }
    }	    
    return answer;
}
