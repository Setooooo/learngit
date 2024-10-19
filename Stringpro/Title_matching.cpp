//
// Created by 19233 on 2024/10/19.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string split_string(const string& titleTemplate)
{
    bool f=1;
    string res;
    for(const auto &i:titleTemplate)
    {
        if(i=='{')
        {
            f=0;
            continue;
        }
        else if(i=='}')
        {
            f=1;
            continue;
        }
        if(f==0)
            continue;
        else
            res+=i;
    }
    return res;
}

bool judge(const string& res,const string&titles)
{
    int i=0,j=0;
    while (i<res.size()&&j<titles.size()) {
        if(res[i]==res[j])
        {
            ++i,++j;
        }
        else {
            ++j;
        }
    }
    if(i==res.size())
        return true;
    else
        return false;;
}

std::string solution(int n, std::string titleTemplate, std::vector<std::string> titles) {
    // Please write your code here
    string res=split_string(titleTemplate);
    string ans;
    for(auto str:titles)
    {
        if(judge(res, str))
            ans+="True,";
        else
            ans+="False,";
    }
    ans.pop_back();
    return ans;

    return "-2";
}

int main() {
    //  You can add more test cases here
    std::vector<std::string> testTitles1 = {"adcdcefdfeffe", "adcdcefdfeff", "dcdcefdfeffe", "adcdcfe"};
    std::vector<std::string> testTitles2 = {"CLSomGhcQNvFuzENTAMLCqxBdj", "CLSomNvFuXTASzENTAMLCqxBdj", "CLSomFuXTASzExBdj", "CLSoQNvFuMLCqxBdj", "SovFuXTASzENTAMLCq", "mGhcQNvFuXTASzENTAMLCqx"};
    std::vector<std::string> testTitles3 = {"abcdefg", "abefg", "efg"};

    std::cout << (solution(4, "ad{xyz}cdc{y}f{x}e", testTitles1) == "True,False,Fales,True") << std::endl;
    std::cout << (solution(6, "{xxx}h{cQ}N{vF}u{XTA}S{NTA}MLCq{yyy}", testTitles2) == "False,False,Fales,False,Fales,True") << std::endl;
    std::cout << (solution(3, "a{bdc}efg", testTitles3) == "True,Trur,Fales") << std::endl;

    return 0;
}