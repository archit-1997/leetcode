/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : graphValidTree.cpp
 * @created     : Thursday Jul 29, 2021 12:30:46 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    
    bool dfs(vector<vector<int>> &graph,vector<int> &vis,vector<int> &rec,int x){
        vis[x]=1;
        rec[x]=1;
        for(int i=0;i<graph[x].size();i++){
            int curr=graph[x][i];
            if(vis[curr] || rec[curr])
                return false;
            if(!dfs(graph,vis,rec,curr))
                return false;
        }
        rec[x]=0;
        return true;
    }

    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        vector<vector<int>> graph(n);
        for(vector<int> edge : edges)
            graph[edge[0]].push_back(edge[1]);

        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            //do dfs from every node
            if(graph[i].size()>0 && !vis[i]){
                vector<int> rec(n,0);
                if(!dfs(graph,vis,rec,i))
                    return false;
            }
        }
        return true;

    }
};
