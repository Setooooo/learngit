//
// Created by 19233 on 2024/9/29.
//
//https://codeforces.com/contest/1999/problem/G2

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

int main(){

    int T,x;
    cin>>T;
    while (T--) {
        int l = 1, r = 999, m1, m2;
        while (l<r)
        {
            m1=(r-l)/3+l,m2=r-(r-l)/3;
            cout<<"? "<<m1<<" "<<m2<<endl;
            cin>>x;
            if(x==(m1+1)*(m2+1))
            {
                r=m1;
            }
            else if(x==(m1)*(m2+1))
            {
                l=m1+1;
                r=m2;
            }
            else
            {
                l=m2+1;
            }
        }
        cout<<"! "<<l<<endl;
    }


    return 0;
}