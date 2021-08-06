/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : minDistanceToTragetElement.cpp
 * @created     : Friday Aug 06, 2021 10:53:39 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        int diff=INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]==target){
                if(abs(i-start)<diff)
                    diff=abs(i-start);
            }
        }
        return diff;
    }
};

