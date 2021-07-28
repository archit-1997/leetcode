/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : cyclicallyRotatingAGrid.cpp
 * @created     : Wednesday Jul 28, 2021 20:10:51 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size(),c=grid[0].size();
        
        //extract layer by layer
        int up=0,down=r-1,left=0,right=c-1;
        while(up<down && left<right){
            vector<int> v;
            //traverse the first row
            for(int j=left;j<=right;j++)
                v.push_back(grid[up][j]);
            up++;

            //traverse the rightmost col
            for(int i=up;i<=down;i++)
                v.push_back(grid[i][right]);
            right--;

            //traverse the bottomost row
            for(int j=right;j>=left;j--)
                v.push_back(grid[down][j]);
            down--;

            //traverse the left col
            for(int i=down;i>=up;i--)
                v.push_back(grid[i][left]);
            left++;
            
            //now I have all the values of the this layer
            int n=v.size();
            // for(int i=0;i<v.size();i++)
            //     cout<<v[i]<<" ";
            // cout<<"\n";

            int count=k;
            count=count%n;

            //now rotate this vector by k
            vector<int> rep(n);
            for(int i=0;i<n;i++)
                rep[i]=v[(i+count)%n];
            
            // for(int i=0;i<n;i++)
            //     cout<<rep[i]<<" ";

            //fill rep again back into the array
            int fup=up-1,fdown=down+1,fleft=left-1,fright=right+1;

            int index=0;
            //traverse the first row
            for(int j=fleft;j<=fright;j++)
                grid[fup][j]=rep[index++];
            fup++;

            //traverse the rightmost col
            for(int i=fup;i<=fdown;i++)
                grid[i][fright]=rep[index++];
            fright--;

            //traverse the bottomost row
            for(int j=fright;j>=fleft;j--)
                grid[fdown][j]=rep[index++];
            fdown--;

            //traverse the left col
            for(int i=fdown;i>=fup;i--)
                grid[i][fleft]=rep[index++];
            fleft++;
        }
        return grid;
    }
};

