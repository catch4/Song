#include <iostream>
#include <vector>
#include <algorithm>
int pivot,n,answer;

void assign(const int& num){
    int an_diff = abs(answer-pivot),n_diff = abs(num-pivot);
    if(an_diff> n_diff) answer=num;
    else if(an_diff==n_diff && answer>num) answer=num;
}

int main(){
    int t; std::cin>>t;
    while(t--){
        answer=-2000000000;
        std::cin>>pivot>>n;
        std::vector<int> vec(n),sum1(n*n),sum2(n*n);
        for(int i=0;i<n;i++) std::cin>>vec[i];
        for(int i=0;i<n;i++){
            int num; std::cin>>num;
            for(int j=i*n, z=0 ;z<n;j++,z++)
                sum1[j]=num+vec[z];
        }
        for(int i=0;i<n;i++) std::cin>>vec[i];
        for(int i=0;i<n;i++){
            int num; std::cin>>num;
            for(int j=i*n, z=0 ;z<n;j++,z++)
                sum2[j]=num+vec[z];
        }
        sort(sum2.begin(),sum2.end());
        for(int i=0;i<n*n;i++)
        {
            int res = pivot - sum1[i];
            int idx = std::lower_bound(sum2.begin(),sum2.end(),res) - sum2.begin();
            assign(sum1[i]+sum2[idx]);
            if(idx>0)
                assign(sum1[i]+sum2[idx-1]);
        }
        std::cout<<answer<<'\n';
    }
}