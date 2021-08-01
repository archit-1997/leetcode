/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : courseSchedule.cpp
 * @created     : Sunday Aug 01, 2021 17:31:53 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> buildGraph(int numCourses,vector<vector<int>> &prerequisites){
        vector<vector<int>> graph(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0],b=prerequisites[i][1];
            //complete course b before a
            graph[b].push_back(a);
        }
        return graph;
    }

    bool detectCycle(vector<vector<int>> &graph,int numCourses,vector<int> &vis,vector<int> &rec,int x){
        rec[x]=1;
        vis[x]=1;

        for(int i=0;i<graph[x].size();i++){
            int cur=graph[x][i];
            //already present in the recursion stack
            if(rec[cur])
                return true;
            //if not visited, but there is a cylce later on
            if(!vis[i] && detectCycle(graph,numCourses,vis,rec,cur))
                return true;
        }
        //no cycles for this node
        rec[x]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //if there is only one course, then you can just say finished
        if(numCourses==1)
            return true;

        //build the graph
        vector<vector<int>> graph=buildGraph(numCourses,prerequisites);
        
        vector<int> vis(numCourses,0);
        //vector for recursion stack
        vector<int> rec(numCourses,0);

        //check for the existence of cycle in the graph
        //need to apply dfs from each node
        for(int i=0;i<numCourses;i++){
            if(detectCycle(graph,numCourses,vis,rec,i))
                return false;
        }
        //no cycle in the graph, then we can complete all the courses
        return true;
    }
};
