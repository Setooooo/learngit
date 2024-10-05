//
// Created by 19233 on 2024/9/23.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <string>
#include <string>
#include <iomanip>

using namespace std;

long long r,l,dp[11][10];

void initial()
{
    for(int i=0;i<=9;++i)
    {
        dp[1][i]=1;
    }
    for(int i=2;i<=10;++i)
    {
        for(int j=0;j<=9;++j)
        {
            for(int x=0;x<10;++x)
            {
                if(abs(j-x)>=2)
                    dp[i][j]+=dp[i-1][x];
            }
        }
    }
}

long long count_ans(int top)
{
    long long res=top,len=0;
    int pos[11];
    while (res)
    {
        pos[++len]=res%10;
        res/=10;
    }
    for(int i=1;i<len;i++)
    {
        for(int j=1;j<10;++j)
        {
            res+=dp[i][j];
        }
    }
    for(int i=1;i<pos[len];++i)
        res+=dp[len][i];
    for(int i=len-1;i>=1;--i)
    {
        for(int j=0;j<pos[i];++j)
        {
            if(abs(pos[i+1]-j)>=2)
                res+=dp[i][j];
        }
        if(abs(pos[i]-pos[i+1])<2)
            break;
    }
    return res;
}




int main() {
    cin>>l>>r;
    initial();
    cout<<count_ans(r+1)- count_ans(l);


    return 0;
}