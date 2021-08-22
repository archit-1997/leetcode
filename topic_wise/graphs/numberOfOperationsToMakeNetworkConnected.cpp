/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : numberOfOperationsToMakeNetworkConnected.cpp
 * @created     : Sunday Aug 22, 2021 16:48:07 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    vector<vector<int>> buildGraph(vector<vector<int>> &edges,int n){
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        return graph;
    }

    void dfs(vector<vector<int>> &graph,vector<int> &vis,int x){
        vis[x]=1;
        for(int i=0;i<graph[x].size();i++){
            int cur=graph[x][i];
            if(!vis[cur])
                dfs(graph,vis,cur);
        }
    }

    int components(vector<vector<int>> &edges,int n){
        vector<vector<int>> graph=buildGraph(edges,n);

        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,vis,i);
                ans++;
            }
        }
        return ans;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        //if we have insufficient number of edges
        if(connections.size()<n-1)
            return -1;
        int ans=components(connections,n);
        return ans-1;
    }
};
