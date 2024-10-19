//
// Created by 19233 on 2024/10/18.
//
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

int ans=0;

vector<vector<int>> pre(vector<int>&numbers)
{
    vector<vector<int>>group(numbers.size());
    int j=0;
    for(auto i:numbers)
    {
        while (i)
        {
            group[j].push_back(i%10);
            i/=10;
        }
        ++j;
    }
    return group;
}

void dfs(int ceng ,int j ,vector<vector<int>>&group)
{
    if(ceng==0)
    {
        if(j&1)
            return;
        else
            ++ans;
    }
    else
    {
        for(auto i:group[ceng-1])
        {
            if(i&1)
                dfs(ceng-1,j+1,group);
            else
                dfs(ceng-1,j,group);
        }
    }
}

int solution(std::vector<int> numbers) {
    // Please write your code here
    ans=0;
    vector<vector<int>>group=pre(numbers);
    dfs(numbers.size(),0,group);

    return ans;
}

int main() {
    // You can add more test cases here
    std::cout << (solution({123, 456, 789}) == 14) << std::endl;
    std::cout << (solution({123456789}) == 4) << std::endl;
    std::cout << (solution({14329, 7568}) == 10) << std::endl;
    return 0;
}