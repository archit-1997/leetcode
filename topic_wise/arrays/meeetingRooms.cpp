/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : meeetingRooms.cpp
 * @created     : Tuesday Aug 24, 2021 07:43:02 IST
 */

#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a,vector<int> &b){
    if(a[0]==b[0])
        return a[1]<b[1];
    return a[0]<b[0];
}

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0)
            return true;

        sort(intervals.begin(),intervals.end(),compare);
        int start=intervals[0][0],end=intervals[0][1];

        for(int i=1;i<n;i++){
            start=intervals[i][0];
            if(start<end)
                return false;
            end=max(end,intervals[i][1]);
        }
        return true;
    }
};
