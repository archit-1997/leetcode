#include <bits/stdc++.h>
using namespace std; 

#define ll long long int
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int r=points.size(),c=points[0].size();
        vector<ll> prev(c,0);

        for(int j=0;j<c;j++)
            prev[j]=points[0][j];

        for(int i=1;i<r;i++){
            //copy the value of current row in points
            vector<ll> left(c,0),right(c,0);

            //max from the left side
            left[0]=prev[0];
            for(int j=1;j<c;j++)
                left[j]=max(prev[j],left[j-1]-1);

            //max from the right side
            right[c-1]=prev[c-1];
            for(int j=c-2;j>=0;j--)
                right[j]=max(prev[j],right[j+1]-1);
            
            //new vector for the current row
            vector<ll> cur(c,0);
            //find the max value for each cell
            for(int j=0;j<c;j++)
                cur[j]=max(left[j],right[j])+points[i][j];

            //assinging for next iteration
            prev=cur;
        }
        return *max_element(prev.begin(),prev.end());
    }
};

