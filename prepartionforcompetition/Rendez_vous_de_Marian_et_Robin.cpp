//
// Created by 19233 on 2024/9/28.
//
//https://codeforces.com/problemset/problem/2014/E

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

const int INF=numeric_limits<int>::max();

static auto p=[](const pair<int,int>&a,const pair<int,int>&b){return a.second<b.second;};

class Meet
{
    friend void solve(Meet&a,Meet&b);
public:
    Meet(int n,int m,int h):graph(n+1),distance(n+1,INF),horse(n+1,0){
        distance[1]=0;
        int x,y,w;
        for(int i=0;i<h;++i)
        {
            cin>>x;
            horse[x]=1;
        }
        for(int i=0;i<m;++i)
        {
            cin>>x>>y>>w;
            graph[x].emplace_back(y,w);
            graph[y].emplace_back(x,w);
        }

    }
    Meet(const Meet&other):graph(other.graph),distance(other.distance),pq(other.pq){}
    void Dijkstra(int x);

private:
    vector<vector<pair<int, int>>> graph;
    vector<int>distance;
    priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(p)>pq{p};
    vector<bool>horse

};

void Meet::Dijkstra(int n) {
    pq.push({n,0});
    while (!pq.empty())
    {
        int x=pq.top().first,y=pq.top().second;
        pq.pop();
        if(y>distance[x]) {
            continue;
        }
        if(horse[x]=1)
        {
            for(auto &[i,j]:graph[x])
            {
                horse[i]=1;
            }
        }
        else
        {
            for(auto &i:graph[x])
            {
                if(i.second+distance[x]<distance[i.first])
                {
                    distance[i.first]=i.second+distance[x];
                    pq.push({i.first,distance[i.first]});
                }
            }
        }

    }
}

void solve(Meet&a,Meet&b){
    int n=b.distance.size()-1;
    a.Dijkstra(1);b.Dijkstra(n);
    int
    for(int i=1;i<=n;++i)
    {

    }
}


int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n,m,h;
        cin>>n>>m>>h;
    }

    return 0;
}