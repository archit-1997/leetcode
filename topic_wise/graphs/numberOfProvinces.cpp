/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : numberOfProvinces.cpp
 * @created     : Wednesday Aug 25, 2021 14:29:55 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int r,c;

    vector<vector<int>> buildGraph(vector<vector<int>> &isConnected){
        vector<vector<int>> graph(r);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(isConnected[i][j]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        return graph;
    }

    void dfs(vector<vector<int>> &graph,vector<int> &vis,int x){
        vis[x]=1;;
        for(int i=0;i<graph[x].size();i++){
            int cur=graph[x][i];
            if(!vis[cur])
                dfs(graph,vis,cur);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        r=isConnected.size(),c=isConnected[0].size();

        vector<vector<int>> graph=buildGraph(isConnected);
        int ans=0;

        vector<int> vis(r,0);
        for(int i=0;i<r;i++){
            if(!vis[i]){
                dfs(graph,vis,i);
                ans++;
            }
        }

        return ans;
    }
};

