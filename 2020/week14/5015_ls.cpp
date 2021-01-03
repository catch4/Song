/*
Catch study 14����
����_ls
https://www.acmicpc.net/problem/5015
*/
/*-----------------
Ǯ��
i = ���Խ� idx, j = string idx
1. *�� ��� i++
2. ù���ڶ� ���������ڰ� *�ƴ� ���� string������ ù,������ ���� �����ؾ���
3. re�� ���� idx ���� *�� ��� ���� idx�� �����Ҷ����� j++
4. re�� ���� idx ���� *�� �ƴ� ��� �ٷ� �����ؾ���
5. string�� �� Ȯ�� �ߴµ� re�� Ȯ�� �ȳ��� ��� Ȯ�� ���� re�� ��� *���� ����
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
			if(i==re.size()) return true; // ����
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
