/*
Catch study 10����
����_��ȭ��ȣ ���
https://www.acmicpc.net/problem/5052
*/
/*-----------------
Ǯ��
���α׷��ӽ����� ����Ѱ� Ǯ�

[119, 456, 789,119123] �����ϸ�
[119,119123,456,789]������ �Ǽ� �յڸ� ���ϸ��

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
