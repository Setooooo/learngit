//
// Created by 19233 on 2024/9/30.
//
//https://codeforces.com/contest/1997/problem/D

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

const int N=1000000007;

class MaxRoot
{
public:
    MaxRoot(int n):tree(n+1),value(n+1){
        for(int i=1;i<=n;++i)
            cin>>value[i];
        int v;
        for(int i=2;i<=n;++i)
        {
            cin>>v;
            tree[v].push_back(i);
        }
    }
    void solve(){
        int ans=N;
        for(auto &i:tree[1])
        {
            ans=min(ans, dfs(i));
        }
        cout<<ans+value[1]<<endl;
    }
    int dfs(int x);
private:
    vector<vector<int>>tree;
    vector<int>value;
};

int MaxRoot::dfs(int x) {
    int reser=N;
    for(auto i:tree[x])
    {
        reser=min(dfs(i),reser);
    }
    if(reser!=N)
    {
        return value[x]<reser?(value[x]+reser)/2:reser;
    }
    else
        return value[x];
}


int main()
{
    int T,n;
    cin>>T;
    while (T--)
    {
        cin>>n;
        MaxRoot(n).solve();
    }

    return 0;
}