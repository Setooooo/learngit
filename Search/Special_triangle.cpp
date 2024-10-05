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


using namespace std;

const int N=1e6+7;

vector<int>cnt(N,0);

void dfs(int dep,int pre,int mult,int sum) {
    if(mult>=N)return;
    if(dep==4){++cnt[mult];return;}

    int mun_max=pow(N/mult,1.0/(4.0-dep))+3;
    for(int i=pre+1;i<(dep==3?sum:mun_max);++i) {
        dfs(dep+1,i,mult*i,sum+i);
    }
}




int main() {
    dfs(1,0,1,0);

    // for(int i=1;i<=100;++i) {
    //     for(int j=i+1;j<=1000;++j) {
    //         if(i*j>N)break;
    //         int maxe=min((j+i-1),(N/(i*j)));
    //         if(maxe<=j)continue;
    //
    //         for(int e=j+1;e<=maxe;++e) {
    //             ++cnt[e*j*i];
    //         }
    //     }
    // }
    for(int i=1;i<N;++i) {
        cnt[i]+=cnt[i-1];
    }
    int T,l,r;
    cin>>T;
    while (T--) {
        cin>>l>>r;
        cout<<cnt[r]-cnt[l-1]<<'\n';
    }

    return 0;
}