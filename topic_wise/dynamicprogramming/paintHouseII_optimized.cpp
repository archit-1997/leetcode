/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : paintHouseII_optimized.cpp
 * @created     : Tuesday Aug 17, 2021 21:59:43 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> findTwoMinimum(vector<int> &v){
        int small=INT_MAX,smallIndex=INT_MAX,small2=0,small2Index=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            if(v[i]<small){
                //so we need to update big and small
                small2=small;
                small2Index=smallIndex;
                small=v[i];
                smallIndex=i;
            }
            else if(v[i]<small2){   
                //here we only need to update small2
                small2=v[i];
                small2Index=i;
            }
        }

        vector<vector<int>> ans={{small,smallIndex},{small2,small2Index}};
        return ans;
    }

    int minCostII(vector<vector<int>>& costs) {
        //for every row(except the last row, we need to find the min and the second min element)
        int r=costs.size(),c=costs[0].size();
        for(int i=1;i<r;i++){
            //finding the two min element with their index from the above two row
            vector<vector<int>> twoMin=findTwoMinimum(costs[i-1]);

            //for every element, check with the twoMin element array
            for(int j=0;j<c;j++){
                //check for the first element
                if(twoMin[0][1]!=j)
                    costs[i][j]+=twoMin[0][0];
                else
                    //this means that we have to choose the second element
                    costs[i][j]+=twoMin[1][0];
            }
        }
        
        //now we just need to return the max element in the last row
        return *min_element(costs[r-1].begin(),costs[r-1].end());
    }
};

