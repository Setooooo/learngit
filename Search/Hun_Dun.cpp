//
// Created by 19233 on 2024/9/16.
//
//记得数组不能开的很大
//还有写代码注意变量名，记得检查代码补全

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <string.h>



using namespace std;

int n,m,k,sx,sy,ex,ey;

int hun_dun[1005][1005];
int dp[1005][1005][3];

int nx[4]={0,0,1,-1},ny[4]={1,-1,0,0};

bool inmap(int x,int y) {
    return x>=1 && y>=1 && x<=n && y<=m;
}


bool dfs(int x,int y,int t) {
    if(x==ex&&y==ey) return dp[x][y][t]=1;
    if(dp[x][y][t]!=-1) return dp[x][y][t];

    for(int i=0;i<4;i++) {
            int hx=x+nx[i],hy=y+ny[i];
            if(!inmap(hx,hy))continue;
            if(!t) {
                if(hun_dun[hx][hy]<hun_dun[x][y]&&dfs(hx,hy,0)) return dp[x][y][t]=1;
                if(hun_dun[hx][hy]<hun_dun[x][y]+k&&dfs(hx,hy,1)) return dp[x][y][t]=1;
            }
            else
                if(hun_dun[hx][hy]<hun_dun[x][y]&&dfs(hx,hy,1)) return dp[x][y][t]=1;
    }
    return dp[x][y][t]=0;
}


int main() {
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    cin>>sx>>sy>>ex>>ey;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>hun_dun[i][j];

    cout<<(dfs(sx,sy,0)?"Yes":"No")<<endl;

    return 0;
}