/*
Catch study 14주차
백준_ls
https://www.acmicpc.net/problem/5015
*/
/*-----------------
풀이
i = 정규식 idx, j = string idx
1. *일 경우 i++
2. 첫글자랑 마지막글자가 *아닐 때는 string에서도 첫,마지막 글자 동일해야함
3. re의 이전 idx 값이 *일 경우 현재 idx랑 동일할때까지 j++
4. re의 이전 idx 값이 *이 아닐 경우 바로 동일해야함
5. string을 다 확인 했는데 re는 확인 안끝난 경우 확인 못한 re가 모두 *여야 가능
-----------------*/
#include <iostream>
#include <vector>
#include <string>

std::string re;
bool regex_match(std::string& str){
	int i=0,j=0;
	while(i<re.size()&&j<str.size()){
		if(re[i]=='*'){ // 1.
			i++;
			if(i==re.size()) return true; // 성공
		}
		if(re[i]!='*')
		{
			// 2.
			if(!i&&re[0]!=str[0]){ 
				if(re[0]!=str[0]) return false;
				else{
					i++;
					j++;
				}
			}
			else if(i==re.size()-1) {
				if(re[re.size()-1]!=str[str.size()-1]) return false;
				else return true;
			}
			// 3.
			else if(i&&re[i-1]=='*'){
				while(j<str.size()&&re[i]!=str[j])
					j++;
				if(j>=str.size()) return false;
				i++;
				j++;
			}
			// 4.
			else{
				if(re[i]!=str[j]) return false;
				i++;
				j++;
			}
		}
	}
	// 5.
	if(i<re.size()){ 
		for(;i<re.size();i++)
			if(re[i]!='*') return false;
		return true;
	}
	else return true;
}

int n;
int main(){
	std::string str; std::cin>>re>>n;
	for(int i=0;i<n;i++){
		std::cin>>str;
		if(regex_match(str))
			std::cout<<str<<'\n';
	}
	return 0;
}
