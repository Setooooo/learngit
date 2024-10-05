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
const int N=1e5+7;

int a[N],indx,mindx,ans,dfn[N];

int dfs(int x) {
    dfn[x]=++indx;
    if(dfn[a[x]]) {
        if(dfn[a[x]]>=mindx)return dfn[x]-dfn[a[x]]+1;
        return 0;
    }
    return dfs(a[x]);
}


int main() {

    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i) {
        if(dfn[i])continue;
        mindx=indx+1;
        ans=max(ans,dfs(i));
    }
    cout<<ans;

    return 0;
}