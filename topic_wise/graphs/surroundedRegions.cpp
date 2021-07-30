/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : surroundedRegions.cpp
 * @created     : Thursday Jul 29, 2021 11:35:36 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isValid(int x,int y, int row,int col){
        return (x>=0 && x<row && y>=0 && y<col);
    }

    void dfs(vector<vector<char>>& board,vector<vector<int>> &vis,int x,int y){
        //mark the current cell as visited
        int row=board.size(),col=board[0].size();
        vis[x][y]=1;

        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};

        //traverse in all the four directions and do dfs
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];

            if(isValid(x1,y1,row,col) && !vis[x1][y1] && board[x1][y1]=='O')
                dfs(board,vis,x1,y1);

        }
    }

    void solve(vector<vector<char>>& board) {
        int r=board.size(),c=board[0].size();
        
        //traverse all the boundary zeroes and if you find a 0, then dfs and mark all as zeroes
        vector<vector<int>> vis(r,vector<int> (c,0));

        //traverse the top and the bottom row
        for(int j=0;j<c;j++){
            if(board[0][j]=='O' && !vis[0][j])
                dfs(board,vis,0,j);
            if(board[r-1][j]=='O' && !vis[r-1][j])
                dfs(board,vis,r-1,j);
        }
        
        //traverse the left and rigt column
        for(int i=0;i<r;i++){
            if(board[i][c-1]=='O' && !vis[i][c-1])
                dfs(board,vis,i,c-1);
            if(board[i][0]=='O' && !vis[i][0])
                dfs(board,vis,i,0);
        }

       //if there is an 'O' which is not visited yet, mark it as x
       for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!vis[i][j] && board[i][j]=='O')
                    board[i][j]='X';
            }
       }
    

    }
};
