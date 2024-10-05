//
// Created by 19233 on 2024/9/28.
//
//https://codeforces.com/problemset/problem/2014/F

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Defence
{
public:
    Defence(int n,int _c):dp(n+1,vector<long long>(2,0)),val(n+1),tree(n+1),vis(n+1,false),c(_c){
        for(int i=1;i<=n;++i)
            cin>>val[i];
        int x,y;
        for(int i=1;i<n;++i)
        {
            cin>>x>>y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        dfs(1);
    }
    void dfs(int x);
    void solve(){cout<<max(dp[1][1],dp[1][0])<<endl;}

private:
    vector<vector<long long>>dp;
    vector<int>val;
    vector<vector<int>>tree;
    vector<bool>vis;
    int c;
};

void Defence::dfs(int x) {
    dp[x][1]=val[x];
    if(vis[x])
        return;
    vis[x]=1;
    for(auto &i:tree[x])
    {
        if(vis[i])
            continue;
        else
            dfs(i);
        dp[x][0]+=max(dp[i][1],dp[i][0]);
        dp[x][1]+=max(dp[i][1]-2*c,dp[i][0]);
    }
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n,c;
        cin>>n>>c;
        Defence(n,c).solve();
    }

    return 0;
}