/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : minCostToReachDestinationInTime.cpp
 * @created     : Friday Jul 23, 2021 13:17:57 IST
 */


#include <bits/stdc++.h>
using namespace std;

#define P pair<int,pair<int,int>>

class Solution {
public:

vector<vector<pair<int,int>>> constructGraph(vector<vector<int>>& edges,int n){
    vector<vector<pair<int,int>>> graph(n);
    for(auto e : edges){
        graph[e[0]].push_back({e[1],e[2]});
        graph[e[1]].push_back({e[0],e[2]});
    }
    return graph;
}

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<vector<pair<int,int>>> graph=constructGraph(edges,n);

        priority_queue<P,vector<P>,greater<P>> q;

        //{passingFees,{nextNode,time}}
        q.push({passingFees[0],{0,0}});

        unordered_map<int,int> vis;

        int ans=0;
        while(!q.empty()){
            pair<int,pair<int,int>> t=q.top();
            q.pop();

            int cost=t.first;
            int curNode=t.second.first,curTime=t.second.second;

            //reached the last node ?
            if(curNode==(n-1))
                return cost;

            //mark visited with current time
            vis[curNode]=curTime;

            for(int i=0;i<graph[curNode].size();i++){
                int nextNode=graph[curNode][i].first;
                int nextTime=graph[curNode][i].second;

                int time=curTime+nextTime;

                //if curnode already visited and also with a smaller time
                if(vis.find(nextNode)!=vis.end() && vis[nextNode]<=time)
                    continue;

                //we need to mark this node as visited
                vis[nextNode]=time;

                //push in queue only if time <= totalTime
                if(time<=maxTime)
                    q.push({passingFees[nextNode]+cost,{nextNode,time}});
            }

        }
        return -1;
    }
};
