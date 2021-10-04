/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : islandPerimeter.cpp
 * @created     : Monday Oct 04, 2021 20:24:52 IST
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

    bool isValid(int x,int y,int r,int c){
        return (x>=0 && x<r && y>=0 && y<c);
    }

    bool isFilled(vector<vector<int>> &grid,int x,int y){
        int r=grid.size(),c=grid[0].size();

        return (isValid(x,y,r,c) && grid[x][y]==1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();

        //for every grid, we will just check if there is any other grid which is surrounding it from different sides
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        int ans=0,count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                    ans+=4;
                    //check for all four sides
                    for(int x=0;x<4;x++){
                        int x1=i+dx[x];
                        int y1=j+dy[x];
                        if(isFilled(grid,x1,y1))
                            count+=1;
                    }
                }
            }
        }
        ans-=count;
        return ans;
    }
};
