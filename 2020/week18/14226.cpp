#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct Info{
	int t,n,c;
};

int main() {
	int dst;
	std::cin >> dst;
	std::vector<std::vector<bool>> ck(dst+1,std::vector<bool>(dst+1,0));
	std::queue<Info> Q;
	Q.push({0,1,0});
	while(!Q.empty()){
		Info now = Q.front();
		Q.pop();
		if(now.n==dst){
			std::cout<<now.t<<'\n';
			return 0;
		}
		if(now.c){
			if(now.n+now.c<=dst &&!ck[now.n+now.c][now.c]){
				ck[now.n+now.c][now.c]=1;
				Q.push({now.t+1,now.n+now.c,now.c});
			}
		}
		if(now.n>1 &&! ck[now.n-1][now.c])
		{
			ck[now.n-1][now.c]=1;
			Q.push({now.t+1,now.n-1,now.c});
		}
		if(!ck[now.n][now.n]){
			ck[now.n][now.n]=1;
			Q.push({now.t+1,now.n,now.n});
		}
	}
}
