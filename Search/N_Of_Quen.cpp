//
// Created by 19233 on 2024/9/16.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <string.h>
#include <string>
//写代码应该认真
using namespace std;

int n,cnt;

int quen[11][11];

void dfs(int dep) {
    if(dep==n+1) {
        cnt++;return;
    }

    for(int k=1;k<=n;++k) {
        if(quen[dep][k])continue;
        for(int j=1;j<=n;++j) {
            quen[j][k]++;
        }

        for(int x=dep,y=k;x<=n&&y<=n;++x,++y)quen[x][y]++;
        for(int x=dep,y=k;x>=1&&y<=n;--x,++y)quen[x][y]++;
        for(int x=dep,y=k;x<=n&&y>=1;++x,--y)quen[x][y]++;
        for(int x=dep,y=k;x>=1&&y>=1;--x,--y)quen[x][y]++;

        dfs(dep+1);

        for(int j=1;j<=n;++j){quen[j][k]--;}
        for(int x=dep,y=k;x<=n&&y<=n;++x,++y)quen[x][y]--;
        for(int x=dep,y=k;x>=1&&y<=n;--x,++y)quen[x][y]--;
        for(int x=dep,y=k;x<=n&&y>=1;++x,--y)quen[x][y]--;
        for(int x=dep,y=k;x>=1&&y>=1;--x,--y)quen[x][y]--;
    }
}



int main() {

    cin>>n;
    dfs(1);
    cout<<cnt;
}