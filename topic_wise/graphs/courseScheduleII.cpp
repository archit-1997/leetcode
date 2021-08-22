/* 
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : courseScheduleII.cpp
 * @created     : Sunday Aug 22, 2021 18:48:27 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> buildGraph(int numCourses,vector<vector<int>> &prerequisites){
        vector<vector<int>> graph(numCourses);
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int a=prerequisites[i][0],b=prerequisites[i][1];
            graph[a].push_back(b);
        }
        return graph;
    }

    void dfs(vector<vector<int>> &graph,vector<int> &vis,vector<int> &ans,int x){
        vis[x]=1;

        for(int i=0;i<graph[x].size();i++){
            int cur=graph[x][i];
            if(!vis[cur])
                dfs(graph,vis,ans,cur);
        }
        ans.push_back(x);
    }

    bool detectCycle(vector<vector<int>> &graph,vector<int>&vis,vector<int> &rec,int x){
        vis[x]=1;
        rec[x]=1;

        for(int i=0;i<graph[x].size();i++){
            int cur=graph[x][i];
            //if already present int the recursion stack
            if(rec[cur])
                return true;
            //find for the rest of the graph if this is not visited
            if(!vis[cur] && detectCycle(graph,vis,rec,cur))
                return true;
        }
        rec[x]=0;
        return false;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //this is detect cycle followed by topological sort
        vector<vector<int>> graph=buildGraph(numCourses,prerequisites);

        vector<int> ans;
        vector<int> vis(numCourses,0),rec(numCourses,0);

        //now detect cycle in the graph
        for(int i=0;i<numCourses;i++){
            if(!vis[i] && detectCycle(graph,vis,rec,i))
                return ans;
        }

        //we need to fill the vis array with 0
        fill(vis.begin(),vis.end(),0);
            
        //we will do topological sorting of the graph
        for(int i=0;i<numCourses;i++){
            if(!vis[i])
                dfs(graph,vis,ans,i);
        }

        return ans;
    }
};
