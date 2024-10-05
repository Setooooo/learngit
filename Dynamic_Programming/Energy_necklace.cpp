//
// Created by 19233 on 2024/9/22.
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




int main() {

    int n;
    int x;
    cin>>n;
    vector<int>pre(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>pre[i];
    }
    vector<pair<int,int>>lace(n*2+1);
    for(int i=1;i<n;++i)
    {
        lace[i].first=pre[i],lace[i].second=pre[i+1];
        lace[i+n].first=pre[i],lace[i+n].second=pre[i+1];
    }
    lace[n].first=lace[n*2].first=pre[n],lace[n].second=lace[n*2].second=pre[1];
    vector<vector<int>>dp(n*2+1,vector<int>(n*2+1,0));
    for(int i=1;i<=n-1;++i)
    {
        for(int j=1;j<=n*2-i;++j)
        {
            for(int x=0;x<i;++x)
            {
                dp[j][j+i]=max(dp[j][j+i],dp[j][j+x]+dp[j+x+1][j+i]+lace[j].first*lace[j+x].second*lace[j+i].second);
            }
        }
    }
    int emax=0;
    for(int i=1;i<=n;++i)
        emax= max(emax,dp[i][i+n-1]);
    cout<<emax;


}