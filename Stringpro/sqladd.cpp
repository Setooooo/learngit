//
// Created by 19233 on 2024/10/12.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Node
{
    Node():chi(true),word(),children(27, nullptr){}
    bool chi;
    string word;
    vector<Node *>children;
    Node* insert(char &a){
        int x=a=='_'?26:a-'a';
        if(children[x]== nullptr)
        {
            children[x]=new Node();
        }
        return children[x];
    }
};

void dfs(Node* it,vector<string>&contain)
{
    if(!it->chi)
        contain.push_back(it->word);
    for(auto i:it->children)
    {
        if(i)
            dfs(i,contain);
    }

}

std::string solution(int num, std::vector<std::string> data, std::string input) {
    // Please write your code here
    Node root;
    Node* res=&root;
    for(auto &i:data)
    {
        for(auto &j:i)
        {
               res=res->insert(j);
        }
        res->word=i;
        res->chi= false;
        res=&root;
    }
    for(auto i:input)
    {
        int x=i-'a';
        res=res->children[x];
        if(!res)
        {
            return "-1";
        }

    }
    vector<string >ans;
    dfs(res,ans);
    string sss;
    for(auto i:ans)
        sss+=i+',';
    sss.pop_back();
    return sss;
}

int main() {
    //  You can add more test cases here
    std::vector<std::string> testData1 = {"select", "from", "where", "limit", "origin_log_db", "event_log_table", "user_id", "from_mobile"};
    std::vector<std::string> testData2 = {"select", "from", "where", "limit", "group", "having", "in", "index", "inner", "insert", "like", "log_db", "log_table", "user_id", "group_name", "group_id"};

    std::cout << (solution(8, testData1, "f") == "from,from_mobile") << std::endl;
    std::cout << (solution(16, testData2, "g") == "group,group_name,group_id") << std::endl;
    std::cout << (solution(16, testData2, "m") == "-1") << std::endl;

    return 0;
}