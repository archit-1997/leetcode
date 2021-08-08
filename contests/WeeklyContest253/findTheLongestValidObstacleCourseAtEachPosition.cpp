/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : findTheLongestValidObstacleCourseAtEachPosition.cpp
 * @created     : Sunday Aug 08, 2021 21:08:55 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> res,ans;
        int n=obstacles.size();
        for(int i=0;i<n;i++){
            int val=obstacles[i];
            int index=upper_bound(res.begin(),res.end(),val)-res.begin();
            //if this is the max element, then just insert
            if(index==res.size())
                res.push_back(val);
            else
                res[index]=val;
            ans.push_back(index+1);
        }
        return ans;
    }
};
