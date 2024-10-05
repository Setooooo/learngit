//
// Created by 19233 on 2024/9/27.
//
//http://poj.org/problem?id=1463

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int v,e;
}edge[1510];


int dp[1510][2],n,cnt,head[1510];
void insert(int x,int y)
{
    edge[++cnt].v=y;
    edge[cnt].e=head[x];
    head[x]=cnt;
}



int main()
{
    while ()


    return 0;
}
