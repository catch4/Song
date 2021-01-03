/*
백준_18513 샘터
https://www.acmicpc.net/problem/18513
 */
/*------------------------------------
풀이

BFS 사용
-------------------------------------*/

#include <iostream>
#include <queue>
#include <unordered_map>

int main(){
    int n,k;
    long long answer=0;
    std::cin>>n>>k;
    std::queue<std::pair<int,int>> Q;
    std::unordered_map<int,bool> ck;
    for(int i=0;i<n;i++) {
        int num; std::cin>>num;
        ck[num]=1;
        Q.push({num,0});
    }

    while(!Q.empty() && k){
        int pos = Q.front().first, score = Q.front().second;
        Q.pop();
        if(!ck[pos+1] && pos+1<=100000000){
            k--;
            answer+=score+1;
            if(!k) break;
            Q.push({pos+1,score+1});
            ck[pos+1]=1;
        }
        if(!ck[pos-1]&& pos-1>=-100000000){
            k--;
            answer+=score+1;
            Q.push({pos-1,score+1});
            ck[pos-1]=1;
        }
    }

    std::cout<<answer<<'\n';
    return 0;
}