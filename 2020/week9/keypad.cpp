#include <string>
#include <vector>

using namespace std;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
bool flag=false;
int pos_y;

void RRR(string& answer,std::pair<int,int>& pos,const int& y,const int& x)
{
    answer+="R";
    pos={y,x};
}
void LLL(string& answer,std::pair<int,int>& pos,const int& y,const int& x)
{
    answer+="L";
    pos={y,x};
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    if(hand[0]=='r') flag=true;
    std::pair<int,int> L_pos={3,0},R_pos={3,2};
    for(int i=0;i<numbers.size();i++)
    {
    int x=(numbers[i]-1)%3,y=(numbers[i]-1)/3;
        if(!numbers[i])
        {
            y =3;x=1;
        }
        if(x==2)
        {
        RRR(answer,R_pos,y,x);
        }
        else if(x==0)
        {
       LLL(answer,L_pos,y,x);
        }
        else{
        int l_diff = abs(L_pos.first-y)+abs(L_pos.second-x);
        int r_diff = abs(R_pos.first-y)+abs(R_pos.second-x);
        if(l_diff==r_diff)
            {
            if(flag)
            RRR(answer,R_pos,y,x);
            else
                LLL(answer,L_pos,y,x);
        }
        else{
         if(l_diff<r_diff) LLL(answer,L_pos,y,x);
            else RRR(answer,R_pos,y,x);
        }
        
        }
    
    }
    
    return answer;
}
