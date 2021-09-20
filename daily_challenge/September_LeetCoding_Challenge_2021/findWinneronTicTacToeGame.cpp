/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : findWinneronTicTacToeGame.cpp
 * @created     : Monday Sep 20, 2021 16:28:51 IST
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

    bool hasWon(vector<vector<int>> &grid,int x){
        //check horizontally
        for(int i=0;i<3;i++){
            if(grid[i][0]==x && grid[i][1]==x && grid[i][2]==x)
                return true;
        }

        //check vertically
        for(int j=0;j<3;j++){
            if(grid[0][j]==x && grid[1][j]==x && grid[2][j]==x)
                return true;
        }

        //check diagonally
        if((grid[0][0]==x && grid[1][1]==x && grid[2][2]==x) || (grid[0][2]==x && grid[1][1]==x && grid[2][0]==x))
            return true;

        return false;
    }

    string tictactoe(vector<vector<int>>& moves) {
        int n=moves.size();
        vector<vector<int>> grid(3,vector<int> (3,-1));
        for(int i=0;i<n;i++){
            int x=moves[i][0],y=moves[i][1];

            if(i&1){//B's move
                grid[x][y]=0;
                if(hasWon(grid,0))
                    return "B";
            }
            else{
                grid[x][y]=1;
                if(hasWon(grid,1))
                    return "A";
            }
        }
        if(n==9)
            return "Draw";
        return "Pending";
    }
};
