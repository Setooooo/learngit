//
// Created by 19233 on 2024/9/27.
//
//https://www.luogu.com.cn/problem/P1352

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Dance
{
public:
    Dance(int _n):boss(_n+1,vector<int>()),value(_n+1,0),dp(_n+1,vector<int>(2,0)),fins(_n+1,0){
        int x,y;
        for(int i=1;i<=_n;++i)
        {
            cin>>value[i];
            dp[i][1]=value[i];
        }

        for(int i=1;i<_n;++i)
        {
            cin>>x>>y;
            boss[y].push_back(x);
            fins[x]=1;
        }
        find_boss();
    }
    void solve()
    {
        dfs(final_boss);
        cout<<max(dp[final_boss][0],dp[final_boss][1]);
    }
private:
    void dfs(int x);
    void find_boss();
    vector<vector<int>>boss,dp;
    vector<int>value;
    vector<bool>fins;
    int final_boss=1;

};

void Dance::dfs(int x) {
    for(const auto &i:boss[x])
    {
        dfs(i);
        dp[x][0]+= max(dp[i][1],dp[i][0]);
        dp[x][1]+=dp[i][0];
    }
}

void Dance::find_boss() {
    for(int i=1;i<fins.size();++i)
        if(!fins[i])
        {
            final_boss=i;
            break;
        }
}


int main(){

    int n;
    cin>>n;
    Dance a(n);
    a.solve();

    return 0;
}