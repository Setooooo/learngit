//
// Created by 19233 on 2024/9/19.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <string>
#include <string>
#include <iomanip>

using namespace std;

//状态方程的转移不好想，重叠的子问题是对于两个相同的边缘可以一遍刷上颜色


int main(){
    string a;
    cin>>a;
    int n=a.size();
    a=' '+a;
    vector<vector<int>>conduct(n+1,vector<int>(n+1,1e8));
    for(int i=1;i<=n;++i)
        conduct[i][i]=1;
    for(int i=1;i<=n-1;++i)
    {
        for(int j=1;j<=n-i;++j)
        {
            if(a[j]==a[j+i])
            {
                conduct[j][j+i]=min(conduct[j][j+i-1],conduct[j+1][j+i]);
            }
            else
            {
                for(int x=0;x<i;++x)
                {
                    conduct[j][j+i]=min(conduct[j][j+i],conduct[j][j+x]+conduct[j+x+1][j+i]);
                }
            }
        }
    }
    cout<<conduct[1][n];

    return 0;
}