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

using namespace std;

int under[60][60],n,m,k;
long long int sum[60][60][13][13];
long long p=1e9+7;

int hx[2]={1,0},hy[2]={0,1};

bool check(int i,int j) {
    return i>=1 && i<=n && j>=1 && j<=m;
}

long long dfs(int x,int y,int cnt,int val) {
    if(x==n&&y==m&&cnt==k) {return cnt==k;}
    if(sum[x][y][cnt][val]!=-1) {return sum[x][y][cnt][val];}
    long long int ans=0;
    for(int i=0;i<2;i++) {
        int nx=x+hx[i],ny=y+hy[i];
        if(!check(nx,ny)) continue;
        if(val<under[nx][ny]&&cnt<k) ans=(ans+dfs(nx,ny,cnt+1,under[nx][ny]))%p;
        ans=(ans+dfs(nx,ny,cnt,val))%p;
    }
    return sum[x][y][cnt][val]=ans;
}


int main() {

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
             cin>>under[i][j];
            under[i][j]++;
        }

    memset(sum,-1,sizeof(sum));

    cout<<(p+dfs(1,1,1,under[1][1])+dfs(1,1,0,0))%p<<endl;

    return 0;
}