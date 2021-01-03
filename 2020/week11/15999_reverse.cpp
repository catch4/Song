/*
Catch study 11주차
백준_뒤집기
https://www.acmicpc.net/problem/15999
*/
/*-----------------
풀이
뭔가 dfs 이렇게 짤거였으면 그냥 순서대로 하면 되었을듯

1. 추가 경우가 생기려면 뒤집을 때 주변의 색이 달라야 된다.
2. 구한다음 모든 경우의 수를 구한다. (2^n)
   limit 때문에 for문으로 구현
-----------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#define LIMIT 1000000007
long long answer=0;
int n,m,sum,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
char vec[2000][2000];
bool ck[2000][2000];
void dfs(int& i,int& j)
{
	char ch;
	bool flag=true;
	if(vec[i][j]=='W') // 이거도 굳이 필요 없었음
		ch='B';
	else
		ch='W';

	for(int k=0;k<4;k++)
	{
		int y=i+dy[k],x=j+dx[k];
		if(y<0||y>=n||x<0||x>=m) continue;
		if(ch==vec[y][x])
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		sum+=1; // 1.
		for(int k=0;k<4;k++)
		{
			int y=i+dy[k],x=j+dx[k];
			if(y<0||y>=n||x<0||x>=m||ck[y][x]) continue;
			ck[y][x]=1;
			dfs(y,x);
		}
	}
}

int main(){
        std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin>>n>>m;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			std::cin>>vec[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!ck[i][j]){
				ck[i][j]=1;
				dfs(i,j);
			}
	long long tmp=1;
	for(int i=0;i<sum;i++){ // 2.
		tmp*=2;
		tmp%=LIMIT;
	}
	answer=tmp;
	if(!answer) answer=1;
	std::cout<<answer<<'\n';

	return 0;
}

