/*
백준_14284 간선 이어가기2
https://www.acmicpc.net/problem/14284
 */
/*------------------------------------
풀이

다익스트라 사용
-------------------------------------*/
#include <iostream>
#include <vector>
#include <queue>

struct node{
    int t,c=0;
};

int main(){
    int n,m; std::cin>>n>>m;
    std::vector<std::vector<node>> nodes(n);
    std::vector<int> costs(n,2147000000);
    for(int i=0;i<m;i++){
        int a,b,c; std::cin>>a>>b>>c;
        nodes[a-1].push_back({b-1,c});
        nodes[b-1].push_back({a-1,c});
    }
    std::queue<int> Q;
    int st,dst; std::cin>>st>>dst;
    Q.push(st-1);
    costs[st-1]=0;
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        for(int i=0;i<nodes[now].size();i++){
            if(costs[nodes[now][i].t] > costs[now]+nodes[now][i].c){
                costs[nodes[now][i].t] = costs[now]+nodes[now][i].c;
                Q.push(nodes[now][i].t);
            }
        }
    }
    std::cout<<costs[dst-1]<<'\n';
    return 0;
}