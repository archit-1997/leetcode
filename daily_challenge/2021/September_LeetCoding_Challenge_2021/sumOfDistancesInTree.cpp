/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : sumOfDistancesInTree.cpp
 * @created     : Saturday Sep 04, 2021 18:55:08 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

class Solution {
public:

    vector<vector<int>> graph;
    vector<int> count,ans;

    void populateNodes(int x,int parent){
        for(int i=0;i<graph[x].size();i++){
            int cur=graph[x][i];
            
            //skip the parent : preventing infinite loop
            if(cur==parent)
                continue;
            //populate nodes for the child
            populateNodes(cur,x);
            
            //populate the nodes
            count[x]+=count[cur];

            //update the result
            ans[x]+=ans[cur]+count[cur];
        }

        //adding extra 1 for the node itself
        count[x]+=1;
    }

    void solve(int x,int parent,int n){
        for(int i=0;i<graph[x].size();i++){
            int cur=graph[x][i];
            if(cur==parent)
                continue;

            ans[cur]=ans[x]-count[cur]+n-count[cur];
            solve(cur,x,n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(int i=0;i<n-1;i++){
            int a=edges[i][0],b=edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        count.resize(n);
        ans.resize(n);

        //we need to populate the number of nodes in each subtree
        populateNodes(0,-1);

        //populate the result
        solve(0,-1,n);

        return ans;
    }
};
