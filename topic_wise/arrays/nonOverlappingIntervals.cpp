/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : nonOverlappingIntervals.cpp
 * @created     : Monday Jul 26, 2021 06:36:58 IST
 */


#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),compare);

        int end=intervals[0][1];
        int ans=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<end)
                ans++;
            else{
                end=intervals[i][1];
            }
        }
        return ans;
    }
};
