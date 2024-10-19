//
// Created by 19233 on 2024/10/19.
//
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

std::string solution(int num, std::string data) {
    // Please write your code here
    int total=0,f=0,j=0,inte=0;

    set<int>res;
    vector<int>pos;
    for(const auto &i:data)
    {
        ++j;
        if(i=='R')
        {
            f=1;
            res.insert(j);
        }
        else if(f==1&&i=='L')
        {
            f=0;
            auto x=max_element(res.begin(),res.end());
            if((j-*x)&1)
            {
                continue;
            }
            else {
                pos.push_back((j+*x)/2);
            }
        }
    }
    vector<bool>interal(data.size(),0);
    for(int i=0;i<data.size();++i)
    {
        if(data[i]=='R')
        {
            inte=i;
            interal[inte]= true;
            while(inte<data.size()-1&&data[inte]!='L')
            {
                interal[++inte]=true;
            }
            i=inte;
        }
        else if(data[i]=='L')
        {
            inte=i;
            while (inte>=0 && !interal[inte] && data[inte] != 'R') {
                interal[inte--]=true;
            }
        }
    }
    for(int i=0;i<data.size();++i)
    {
      if(!interal[i])
        pos.emplace_back(i+1);
    }
    sort(pos.begin(),pos.end());
    auto x=[pos](){
        for(const auto&i:pos)
            cout<<i<<' ';
    };
//    x();
    string ans;
    ans+=to_string(pos.size())+':';
    for(const auto&i:pos)
    {
        ans+= to_string(i)+',';
    }
    ans.pop_back();
    return ans;
}

int main() {
    //  You can add more test cases here
    std::cout << (solution(14, ".L.R...LR..L..") == "4:3,6,13,14") << std::endl;
    std::cout << (solution(5, "R....") == "0") << std::endl;
    std::cout << (solution(1, ".") == "1:1") << std::endl;

    return 0;
}