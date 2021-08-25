/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : theMaze.cpp
 * @created     : Wednesday Aug 25, 2021 23:00:50 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};

    int r,c;

    bool isValid(int x,int y){
        return (x>=0 && x<r && y>=0 && y<c);
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        r=maze.size(),c=maze[0].size();
        vector<vector<int>> vis(r,vector<int> (c,0));
        queue<pair<int,int>> q;

        q.push({start[0],start[1]});
        vis[start[0]][start[1]]=1;
        
        while(!q.empty()){
            pair<int,int> t=q.front();
            q.pop();

            int x=t.first,y=t.second;
            //if this is the desired location
            if(x==destination[0] && y==destination[1])
                return true;

            //going in the four directions until we find a wall
            for(int i=0;i<4;i++){
                int x1=x+dx[i],y1=y+dy[i];

                while(isValid(x1,y1) && maze[x1][y1]==0){
                    x1=x1+dx[i];
                    y1=y1+dy[i];
                }

                //if current cell is not visited
                if(!vis[x1-dx[i]][y1-dy[i]]){
                    q.push({x1-dx[i],y1-dy[i]});
                    vis[x1-dx[i]][y1-dy[i]]=1;
                }
            }
        }
        return false;
    }
};

