/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : meetingRoomsII.cpp
 * @created     : Tuesday Aug 24, 2021 08:23:45 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n=intervals.size();

        map<int,int> rooms;
        int ans=0;

        for(int i=0;i<n;i++){
            int start=intervals[i][0],end=intervals[i][1];
            rooms[start]++,rooms[end]--;
        }
        int count=0;
        for(auto it=rooms.begin();it!=rooms.end();it++){
            ans=max(ans,count);
            count+=it->second;
        }
        return ans;
    }
};
