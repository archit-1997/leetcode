/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : paintHouseII.cpp
 * @created     : Tuesday Aug 17, 2021 09:26:07 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int r=costs.size(),c=costs[0].size();
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                //for every element we will run aloop on the previous row 
                //find the min element which is not from the same row
                int ans=INT_MAX;
                for(int k=0;k<c;k++){
                    if(k!=j)
                        ans=min(ans,costs[i-1][k]);
                }
                costs[i][j]=costs[i][j]+ans;
            }
        }
        return *min_element(costs[r-1].begin(),costs[r-1].end());
    }
};
