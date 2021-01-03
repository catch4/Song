/*
Catch study 10주차
백준_되돌리기
https://www.acmicpc.net/problem/1360
*/
/*-----------------
풀이
끝에서 부터 취소 안된 명령만 실행
-----------------*/

#include <iostream>
#include <vector>
#include <string>
#define pi std::pair<int,int>

struct cmd{
	char oper,ch=0;
	bool ck=true;
	int time,del;
	cmd(){}
	cmd(const char& t_o,const int& t_t,const int& t_d,const char& t_ch){
		oper=t_o,time=t_t,del=t_d,ch=t_ch;
	}
};

pi str2int(std::string& str,int cur){
	int num=0;
	for(;cur<str.size()&&str[cur]!=' ';cur++)
		num= num*10+(str[cur]-'0');
	return {num,cur};
}


int main(){
	int n; std::cin>>n;
	std::vector<cmd> cmds(n);
	std::string answer="";
	std::cin.ignore();
	for(int i=0;i<n;i++) {
		std::string str;
		getline(std::cin,str);
		if(str[0]=='t'){
			pi tmp=str2int(str,7);
			cmds[i]=cmd('t',tmp.first,0,str[5]);
		}
		else{
			pi tmp = str2int(str,5);
			int d = tmp.first;
			tmp = str2int(str,tmp.second+1);
			cmds[i]=cmd('u',tmp.first,d,0);
		}
	}
	for(int i=cmds.size()-1;i>=0;i--){
		if(cmds[i].oper=='u'&&cmds[i].ck)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(cmds[j].time>=cmds[i].time-cmds[i].del){
					cmds[j].ck=1-cmds[j].ck;
				}
				else
					break;
			}
		}
	}
	for(int i=0;i<cmds.size();i++)
		if(cmds[i].oper=='t'&&cmds[i].ck)
			answer+=cmds[i].ch;
	std::cout<<answer;

	return 0;
}
