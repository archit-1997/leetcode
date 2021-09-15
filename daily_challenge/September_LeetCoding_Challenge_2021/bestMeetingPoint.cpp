/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : bestMeetingPoint.cpp
 * @created     : Tuesday Sep 14, 2021 14:43:42 IST
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

    int calc(vector<int> &row,int index){
        int n=row.size();

        int ans=0;
        for(int i=0;i<n;i++)
            ans+=abs(row[i]-row[index]);
        return ans;
    }

    int minTotalDistance(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<int> row,col;
        vector<pair<int,int>> v;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        int index=row.size()/2;
        sort(col.begin(),col.end());

        //finding the min distance
        return calc(row,index) + calc(col,index);
    }
};
