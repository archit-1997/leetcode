/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : insertInterval.cpp
 * @created     : Thursday Aug 05, 2021 16:16:32 IST
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),compare);
        int n=intervals.size();
        vector<vector<int>> ans;
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end)
                end=max(end,intervals[i][1]);
            else{
                //we will push this interval
                ans.push_back({start,end});
                start=intervals[i][0],end=intervals[i][1];
            }
        }
        //now we will push the last interval
        ans.push_back({start,end});
        return ans;
    }
};

