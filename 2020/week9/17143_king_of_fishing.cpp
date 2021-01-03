/*
Catch study 9주차
백준_낚시왕
https://www.acmicpc.net/problem/17143
*/
/*-----------------
틀렸던 이유
1씩 ++ 했었는데 시간초과 뜸

풀이
1. 낚시
2. 전체 상어 이동
-----------------*/

#include <iostream>
#include <vector>
#include <queue>
#define vec_2d std::vector<std::vector<int>>

int dx[]={0,0,1,-1},dy[]={-1,1,0,0},r,c,m,sum=0,bound[2];
struct Shark{
	int y,x,s,d,z;
	Shark(){}
	Shark(const int& t_y,const int& t_x,const int& t_s,
			const int& t_d,const int& t_z)
	{
		y=t_y,x=t_x,s=t_s,d=t_d,z=t_z;
	}
	bool operator<(const Shark& bb)const{
		return z<bb.z;
	}
};

void fishing(const int& j,vec_2d& vec){
	for(int i=0;i<r;i++)
	{
		if(vec[i][j]){ 
			sum+=vec[i][j];
			vec[i][j]=0;
			return;
		}
	}

}

void move_shark(Shark& now){
	int pre_pos[2]={now.y,now.x},off[2]={abs(now.s*dy[now.d]),abs(now.s*dx[now.d])};
	int pos[2]={now.y+off[0]*dy[now.d],now.x+off[1]*dx[now.d]};
	while(off[now.d/2]){
		if(pos[now.d/2]>=0&&pos[now.d/2]<bound[now.d/2]) break;
		if(pos[now.d/2]<0)
		{
			pos[now.d/2]=0;
			off[now.d/2]=off[now.d/2]-pre_pos[now.d/2];
		}
		else if(pos[now.d/2]>=bound[now.d/2]){
			pos[now.d/2]=bound[now.d/2]-1;
			off[now.d/2]=off[now.d/2]-(pos[now.d/2]-pre_pos[now.d/2]);
		}
		pre_pos[now.d/2]=pos[now.d/2];
		now.d=(1-(now.d%2))+(now.d/2)*2;
		pos[now.d/2]=pos[now.d/2]+off[0]*dy[now.d]+off[1]*dx[now.d];

	}
	now.y=pos[0],now.x=pos[1];
}

void move_all(vec_2d& vec,std::priority_queue<Shark>& Q){
	vec_2d tmp(r,std::vector<int> (c,0));
	std::priority_queue<Shark> tmp_Q;
	while(!Q.empty()){
		Shark now = Q.top();
		Q.pop();
		if(vec[now.y][now.x]==now.z)
		{
			move_shark(now);
			if(now.z>tmp[now.y][now.x]) {
				tmp[now.y][now.x]=now.z;
				tmp_Q.push(now);
			}
		}
	}
	Q=tmp_Q;
	vec=tmp;
}

int main(){
	std::cin>>r>>c>>m;
	bound[0]=r,bound[1]=c;
	vec_2d vec(r,std::vector<int> (c,0));
	std::priority_queue<Shark> Q;
	for(int i=0;i<m;i++){
		int tr,tc,ts,td,tz;std::cin>>tr>>tc>>ts>>td>>tz;
		Q.push(Shark(tr-1,tc-1,ts,td-1,tz));
		vec[tr-1][tc-1]=tz;
	}
	for(int i=0;i<c;i++){
		fishing(i,vec);
		move_all(vec,Q);
	}
	std::cout<<sum<<'\n';
	return 0;
}
