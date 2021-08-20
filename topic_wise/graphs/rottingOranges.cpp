/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : rottingOranges.cpp
 * @created     : Friday Aug 20, 2021 13:01:53 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isValid(int x,int y,int r, int c){
        return (x>=0 && x<r && y>=0 && y<c);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();

        //inititally we have to count how many fresh oranges are there and also push the rotten oranges into the queue
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                    fresh++;
            }
        }

        if(fresh==0)
            return 0;
        
        vector<vector<int>> vis(r,vector<int> (c,0));

        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};

        //now we just need to apply bfs till the moment fresh count becomes 0
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                pair<int,int> t=q.front();
                q.pop();

                int x=t.first,y=t.second;
                for(int i=0;i<4;i++){
                    int x1=x+dx[i];
                    int y1=y+dy[i];

                    if(isValid(x1,y1,r,c) && grid[x1][y1]==1 && !vis[x1][y1]){
                        //this orange will rot
                        grid[x1][y1]=2;
                        fresh--;
                        vis[x1][y1]=1;
                        q.push({x1,y1});
                    }
                }
            }
            ans++;
            if(fresh<=0)
                return ans;
        }
        return -1;
    }
};
