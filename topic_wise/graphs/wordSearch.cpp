/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : wordSearch.cpp
 * @created     : Friday Aug 06, 2021 08:35:25 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int r,c;
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    int n;
    bool isValid(int x,int y){
        return (x>=0 && x<r && y>=0 && y<c);
    }
    bool dfs(vector<vector<char>> &board,string &word,vector<vector<int>> &vis,int index,int x,int y){
        //if we have reached the last
        if(index==n-1)
            return true;

        vis[x][y]=1;
        
        //go to the next index
        index++;
        
        //dfs in all the directions
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];

            if(isValid(x1,y1) && vis[x1][y1]==0 && board[x1][y1]==word[index]){
                if(dfs(board,word,vis,index,x1,y1))
                    return true;
            }
        }
        vis[x][y]=0;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        r=board.size(),c=board[0].size();
        n=word.size();
        vector<vector<int>> vis(r,vector<int> (c,0));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0]){
                    if( dfs(board,word,vis,0,i,j) )
                        return true;
                }
            }
        }
        return false;
    }
};

