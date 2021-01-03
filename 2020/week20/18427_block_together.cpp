/*
백준_18427 함께 블록 쌓기
https://www.acmicpc.net/problem/18427
*/
/*-----------------------
풀이
dp 이용

틀렸던 이유
처음에는 2개로 그룹 나누고 map으로 계산 -> 시간초과
알고리즘 분류 보고 dp인거 앎
-----------------------*/

#include <iostream>
#include <vector>
#include <string>
int n,m,dst,answer=0;
std::vector<std::vector<int>> vec;

int main(){
    std::cin>>n>>m>>dst;
    vec.resize(n);
    getchar();

    for(int i=0;i<n;i++){
        std::string str; std::getline(std::cin,str);
        int num=0;
        for(int j=0;j<str.size()+1;j++){
            if(j==str.size() || str[j]==' '){
                vec[i].push_back(num);
                num=0;
            }
            else num=num*10 + (str[j]-'0');
        }
        vec[i].push_back(0); // 선택 안된 경우
    }
    std::vector<int> dp(dst+1);
    for(int i=0;i<vec[0].size();i++)
        dp[vec[0][i]]+=1;

    for(int i=1;i<n;i++){
        std::vector<int> temp(dst+1);
        for(int j=0;j<vec[i].size();j++)
        {
            for(int k=0;k<=dst-vec[i][j];k++) // dst값 넘어가면 의미 없어서 dst-vec[i][j] 까지만 돌림
                if(dp[k]){
                    temp[k+vec[i][j]]+=dp[k];
                    temp[k+vec[i][j]]%=10007;
                }
        }
        dp=temp;
    }
    std::cout<<dp[dst]<<'\n';   
}