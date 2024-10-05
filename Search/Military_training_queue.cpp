//
// Created by 19233 on 2024/9/17.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <string>
#include <string>


using namespace std;
int n ,N=12;
int pre[12];

vector<vector<int>>que(N);

bool dfs(int dep,int num) {
    if(dep==n+1)return true;

    for(int i=0;i<num;++i) {
        bool tag=true;
        for(const auto &j:que[i]) {
            if(pre[dep]%j==0) {
                tag=false;
                break;
            }
        }
        if(tag==0)
            continue;
        que[i].push_back(pre[dep]);
        if(dfs(dep+1,num))return true;
        que[i].pop_back();
    }
    return false;
}



int main() {

    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>pre[i];
    sort(pre+1,pre+n+1);
    for(int i=1;i<=n;i++) {
        if(dfs(1,i)) {
            cout<<i;
            break;
        }
    }

    return 0;
}