/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : graphValidTree.cpp
 * @created     : Sunday Aug 22, 2021 15:25:14 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findParent(int x,vector<int> &par){
        while(par[x]!=x){
            par[x]=par[par[x]];
            x=par[x];
        }
        return x;
    }

    bool checkCycle(vector<vector<int>> &edges,int n){
        vector<int> par(n);
        for(int i=0;i<n;i++)
            par[i]=i;
        int len=edges.size();
        for(int i=0;i<len;i++){
            int a=edges[i][0],b=edges[i][1];

            //we need to make parent of a as parent of b
            int pa=findParent(a,par);
            int pb=findParent(b,par);

            if(pa==pb)
                return false;

            //we join them if they have different parents
            par[pa]=pb;
        }

        return true;
    }

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


    bool validTree(int n, vector<vector<int>>& edges) {
        //we need to check for cycle and the number of connected components
        bool res=checkCycle(edges,n);
        int comp=components(edges,n);

        return (res && comp==1);
        
    }
};
