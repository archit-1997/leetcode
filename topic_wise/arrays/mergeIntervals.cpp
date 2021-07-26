/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : meregeIntervals.cpp
 * @created     : Monday Jul 26, 2021 04:51:09 IST
 */


#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &a,const vector<int> &b){
    if(a[0]==b[0])
        return a[1]<b[1];
    return a[0]<b[0];
}

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),compare);
        int start=intervals[0][0],end=intervals[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
            }
            else{
                ans.push_back({start,end});
                start=intervals[i][0],end=intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
