/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : shortestPathToGetFood.cpp
 * @created     : Monday Aug 23, 2021 22:23:22 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int r,c;

    bool isValid(int x,int y){
        return (x>=0 && x<r && y>=0 && y<c);
    }

    void findStartLocation(vector<vector<char>> &grid,int &a,int &b){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='*'){
                    a=i;
                    b=j;
                    return;
                }
            }
        }
    }

    int getFood(vector<vector<char>>& grid) {
        r=grid.size(),c=grid[0].size();

        vector<vector<int>> vis(r,vector<int> (c,0));

        //first we need to find the start location
        int a,b;
        findStartLocation(grid,a,b);

        queue<pair<int,int>> q;
        q.push({a,b});
        vis[a][b]=1;

        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};

        int ans=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                pair<int,int> t=q.front();
                q.pop();
                
                int x=t.first,y=t.second;
                //if this is the target
                if(grid[x][y]=='#')
                    return ans;
                
                for(int i=0;i<4;i++){
                    int x1=x+dx[i];
                    int y1=y+dy[i];

                    if(isValid(x1,y1) && !vis[x1][y1] && grid[x1][y1]!='X'){
                        vis[x1][y1]=1;
                        q.push({x1,y1});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
