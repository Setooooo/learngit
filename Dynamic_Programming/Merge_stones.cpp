//
// Created by 19233 on 2024/9/19.
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
//keep cold 我想在考虑边界时应该冷静，过于随意反而不能在后面的程序实现里随心所欲
//动态规划要考虑好转移方程，不仅仅是想如何转移，还要想好初始状态，和转移方程

int main(){

    int n;
    cin>>n;
    vector<vector<int>>stone(n+1,vector<int>(n+1,1e8));
    vector<int>cost(n+1,0);
    for(int i=1;i<=n;++i)
    {
        cin>>cost[i];
        cost[i]+=cost[i-1];
        stone[i][i]=0;
    }
    for(int i=1;i<=n-1;++i)
    {
        for(int j=1;j<=n-i;++j)
        {
            for(int x=0;x<i;++x)
            {
                stone[j][j+i]=min(stone[j][j+i],stone[j][j+x]+stone[j+x+1][j+i]+cost[j+i]-cost[j-1]);
            }
        }
    }
    cout<<stone[1][n];
}