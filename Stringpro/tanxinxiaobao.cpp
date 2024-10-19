//
// Created by 19233 on 2024/10/17.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int>jiechen(11);
int ans=0;

void pre()
{
    jiechen[0]=0;
    jiechen[1]=1;
    for(int i=2;i<=11;++i)
    {
        jiechen[i]=i*jiechen[i-1];
    }
}

void dfs(int n, int m, int s, const vector<int>&data)
{
    if(m == 0)
    {
        ++ans;
        return;
    }
    else if(n == 0 || m < 0)
    {
        return;
    }
    dfs(n - 1, m, s, data);
    dfs(n - 1, m - data[n - 1], s, data);
    if(s>0)
        dfs(n - 1, m - jiechen[data[n - 1]], s - 1, data);
}


int solution(int n, int m, int s, std::vector<int> like){
    // Edit your code here
    ans=0;
    dfs(n,s,m,like);
    return ans;
}

int main() {
    pre();
    // Add your test cases here
    std::vector<int> like1 = {1, 2, 3};
    std::vector<int> like2 = {1, 1, 1};

    std::cout << (solution(3, 2, 6, like1) == 5) << std::endl;
    std::cout << (solution(3, 1, 1, like2) == 6) << std::endl;
    return 0;
}
