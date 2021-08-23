/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : numberOfConnectedComponentsInUndirectedGraph.cpp
 * @created     : Monday Aug 23, 2021 22:12:34 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> buildGraph(int n,vector<vector<int>> &edges){
        vector<vector<int>> graph(n);
        int len=edges.size();
        for(int i=0;i<len;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        return graph;
    }

    void dfs(vector<vector<int>> &graph,int x,vector<int> &vis){
        vis[x]=1;
        for(int i=0;i<graph[x].size();i++){
            int cur=graph[x][i];
            if(!vis[cur])
                dfs(graph,cur,vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        //build a graph
        vector<vector<int>> graph=buildGraph(n,edges);

        vector<int> vis(n,0);
        int ans=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,i,vis);
                ans++;
            }
        }
        return ans;
    }
};
