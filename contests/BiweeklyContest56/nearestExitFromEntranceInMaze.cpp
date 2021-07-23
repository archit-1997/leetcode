/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : nearestExitFromEntranceInMaze.cpp
 * @created     : Friday Jul 23, 2021 07:27:42 IST
 */


#include <bits/stdc++.h>
using namespace std;

bool isBorderCell(int x,int y,int row,int col){
    if(x==0 || x==row-1 || y==0 || y==col-1)
        return true;
    return false;
}

bool isValidCell(int x,int y,vector<vector<char>>& maze){
    int row=maze.size(),col=maze[0].size();
    if(x>=0 && x<row && y>=0 && y<col && maze[x][y]=='.')
        return true;
    return false;
}

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row=maze.size(),col=maze[0].size();
        
        queue<pair<int,int>> q;
        int a=entrance[0],b=entrance[1];

        vector<vector<int>> vis(row,vector<int> (col,0));
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        q.push({a,b});
        vis[a][b]=1;

        int ans=0;

        while(!q.empty()){
            int s=q.size();
            while(s--){
                pair<int,int> t=q.front();
                q.pop();
                
                int x=t.first,y=t.second; 
                if(isBorderCell(x,y,row,col) && ( x!=a || y!=b ))
                    return ans;

                //go into four directions from this point
                for(int i=0;i<4;i++){
                    int x1=x+dx[i];
                    int y1=y+dy[i];
                    
                    //if this is a valid cell and not visited
                    if(isValidCell(x1,y1,maze) && !vis[x1][y1]){
                        //push into the queue and mark visited
                        q.push({x1,y1});
                        vis[x1][y1]=1;
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};

