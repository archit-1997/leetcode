/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : b.cpp
 * @created     : Saturday Sep 04, 2021 20:08:16 IST
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
    int row,col;

    void dfs(vector<vector<int>> &land,vector<vector<int>> &vis,int x,int y,vector<vector<int>> &ans){
        //go extreme right
        int a=x,b=y,c,d;
        while(y<col && land[x][y])
            y++;
        //if we have reached beyond the matrix, we will come back one step back
        y--;

        //now we will go down
        while(x<row && land[x][y])
            x++;
        //if we have reached out of bound
        x--;

        c=x,d=y;
        //mark everything visited between a,b,c,d
        for(int i=a;i<=c;i++){
            for(int j=b;j<=d;j++)
                vis[i][j]=1;
        }
        ans.push_back({a,b,c,d});
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        row=land.size(),col=land[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(row,vector<int> (col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && land[i][j]==1)
                    dfs(land,vis,i,j,ans);
            }
        }
        return ans;
    }
};
