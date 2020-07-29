/*
Catch study 9주차
백준_상범빌딩
https://www.acmicpc.net/problem/6593
*/
/*-----------------
풀이
3차원 BFS
-----------------*/

#include <iostream>
#include <vector>
#include <queue>


#define vec_3d std::vector<std::vector<std::vector<char>>>
#define vec_3d_b std::vector<std::vector<std::vector<bool>>>
int dz[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dx[]={0,0,0,0,1,-1};

struct Floor{
	int z,y,x,t;
	Floor(){}
	Floor(const int& t_z,const int& t_y,const int& t_x,const int& t_t){
	z=t_z;y=t_y;x=t_x;t=t_t;
	}
};

int main(){
	while(1){
int c,h,w; std::cin>>c>>h>>w;
if(!c&&!h&&!w) break;
vec_3d build(c,std::vector<std::vector<char>> (h,std::vector<char> (w,0)));
vec_3d_b ck(c,std::vector<std::vector<bool>> (h,std::vector<bool> (w,0)));
std::queue<Floor> Q;
bool flag=true;
for(int k=0;k<c;k++)
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{
			std::cin>>build[k][i][j];
			if(build[k][i][j]=='S')
				Q.push(Floor(k,i,j,0));
		}


while(!Q.empty())
{
	Floor now = Q.front();
	Q.pop();
	for(int k=0;k<6;k++)
	{
		int n_x=now.x+dx[k],n_y=now.y+dy[k],n_z=now.z+dz[k];
		if(n_x<0||n_y<0||n_z<0||n_x>=w||n_y>=h||n_z>=c||build[n_z][n_y][n_x]=='#'||ck[n_z][n_y][n_x]) continue;
		if(build[n_z][n_y][n_x]=='E'){
			flag=0;
			std::cout<<"Escaped in "<<now.t+1<<" minute(s).\n";

		}
		ck[n_z][n_y][n_x]=1;
		Q.push(Floor(n_z,n_y,n_x,now.t+1));
	}


}
if(flag) std::cout<<"Trapped!\n";
}
return 0;

}
