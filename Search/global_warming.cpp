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
//注意看题

using namespace std;
const int N=1007;

int ditu[N][N],col,ans,n;
set<int>sheng;
int hx[4]={1,-1,0,0},hy[4]={0,0,-1,1};

bool imap(int x,int y) {
    return x>=1&&x<=n&&y>=1&&y<=n;
}

void dfs(int x,int y) {
    if(ditu[x][y]==-1||ditu[x][y]>0)return;
    ditu[x][y]=col;
    for(int i=0;i<4;++i) {
        int nx=x+hx[i],ny=y+hy[i];
        if(!imap(nx,ny))continue;
        dfs(nx,ny);
    }
}

void warming() {
    for(int i=2;i<n;++i) {
        for(int j=2;j<n;++j) {
            if(ditu[i][j]>0&&ditu[i-1][j]>0&&ditu[i+1][j]>0&&ditu[i][j+1]>0&&ditu[i][j-1]>0) {
                sheng.insert(ditu[i][j]);
            }
        }
    }
}

int main() {
    char a;
    cin>>n;

    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) {
           cin>>a;
            if(a=='.')
                ditu[i][j]=-1;
            else
                ditu[i][j]=0;
        }

    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) {
            if(ditu[i][j]==0) {
                ++col;
                dfs(i,j);
            }
        }
    warming();

    cout<<col-sheng.size();

    return 0;
}