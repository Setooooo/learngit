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

int main(){

    int n,m,ins,add;
    char c;
    cin>>m>>n;
    string a;
    cin>>a;
    a=' '+a;
    map<char,pair<int,int>>fid;
    for(int i=0;i<m;++i)
    {
        cin>>c>>ins>>add;
        fid.insert({c,{ins,add}});
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1,1e6));
    for(int i=1;i<=n;++i)
    {
        dp[i][i]=0;
    }
    for(int i=1;i<=n-1;++i)
    {
        for(int j=1;j<=n-i;++j)
        {
            if(a[i+j]==a[j])
            {
                if(i==1)
                    dp[j][j+i]=0;
                else
                    dp[j][j+i]=dp[j+1][j+i-1];
            }
            else
            {
                int minr=dp[j][j+i-1]+min(fid[a[j+i]].first,fid[a[j+i]].second);
                int minl=dp[j+1][j+i]+min(fid[a[j]].first,fid[a[j]].second);
                dp[j][j+i]=min(minr,minl);
            }
        }
    }
    cout<<dp[1][n];

    return 0;
}