/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : criticalConnectionsInaGraph.cpp
 * @created     : Thursday Aug 26, 2021 18:53:25 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int time;
    vector<vector<int>> buildGraph(vector<vector<int>> &connections,int n){
        vector<vector<int>> graph(n);
        int len=connections.size();

        for(int i=0;i<len;i++){
            int a=connections[i][0],b=connections[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        return graph;
    }

    void dfs(vector<vector<int>> &graph,int x,vector<int> &disc,vector<int> &low,vector<int> &parent,vector<vector<int>> &ans){
        disc[x]=time,low[x]=time;
        time++;

        for(int i=0;i<graph[x].size();i++){
            int cur=graph[x][i];
            //if this is not discovered
            if(disc[cur]==-1){
                //assign the parent for this node
                parent[cur]=x;
                //do dfs from cur
                dfs(graph,cur,disc,low,parent,ans);

                low[x]=min(low[x],low[cur]);

                if(low[cur]>disc[x])
                    ans.push_back({x,cur});
            }
            else if(cur!=parent[x])
                low[x]=min(low[x],disc[cur]);
        }
    }

    vector<vector<int>> findBridges(vector<vector<int>> &graph,int n){
        //answer to store the bridges
        vector<vector<int>> ans;
        //discovery, low and parent vectors
        vector<int> disc(n,-1),low(n,-1),parent(n,-1);

        //if a nodes is undiscovered, dfs for that node
        for(int i=0;i<n;i++){
            if(disc[i]==-1)
                dfs(graph,i,disc,low,parent,ans);
        }
        return ans;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //build graph
        vector<vector<int>> graph=buildGraph(connections,n);
        vector<int> vis(n,0),rec(n,0);
        time=0;
        return findBridges(graph,n);
    }
};
