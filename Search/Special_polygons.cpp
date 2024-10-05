
//
// Created by 19233 on 2024/9/18.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <string>
#include <cmath>

//我想应该认真一点多思考一点
using namespace std;

const int N=1e5+7;
int n;
vector<int>cnt(N,0);

void dfs(int dep,int pre,int multi,int sum) {
    if(multi>=N)return;
    if(dep==n+1){++cnt[multi];return;}

    int maxnum=pow(N/multi,1.0/(n-dep+1.0))+3;
    for(int i=pre+1;i<(dep==n?sum:maxnum);++i) {
        dfs(dep+1,i,multi*i,sum+i);
    }
}


int main() {
    int T,r,l;
    cin>>T>>n;

    dfs(1,0,1,0);

    for(int i=1;i<N;++i)
        cnt[i]+=cnt[i-1];

    while (T--) {
        cin>>l>>r;
        cout<<cnt[r]-cnt[l-1]<<'\n';
    }


}