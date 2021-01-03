/*
Catch study 14����
����_����
https://www.acmicpc.net/problem/13905
*/
/*-----------------
Ǯ��
�̺� Ž������ dfs
dfs�������� mid ������ ���� �������δ� ���� ����
-----------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#define pi std::pair<int,int>
#define t first
#define c second
#define vec_2d std::vector<std::vector<pi>>

int n,m,src,dst,max=0;

bool dfs(vec_2d& vecs,std::vector<bool>& ck,const int& now,int& cost){
	if(now==dst-1){
		return true;
	}
	else{
		for(int i=0;i<vecs[now].size();i++){
			if(vecs[now][i].c<cost || ck[vecs[now][i].t]) continue;
				ck[vecs[now][i].t]=1;
				if(dfs(vecs,ck,vecs[now][i].t,cost)) return true;
				ck[vecs[now][i].t]=0;
			}
	}
	
	return false;
}

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin>>n>>m>>src>>dst;
	vec_2d vecs(n);
	int l=1,r=-1;
	for(int i=0;i<m;i++){
		int s,d,ct; std::cin>>s>>d>>ct;
		vecs[s-1].push_back({d-1,ct});
		vecs[d-1].push_back({s-1,ct});
		r= std::max(r,ct);
	}
	while(l<=r){
		int mid = (l+r)/2;
		std::vector<bool> ck(n);
		ck[src-1]=1;
		if(dfs(vecs,ck,src-1,mid)){
			max=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	std::cout<<max<<'\n';
	return 0;
}
