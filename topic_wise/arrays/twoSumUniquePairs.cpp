/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : twoSumUniquePairs.cpp
 * @created     : Thursday Aug 12, 2021 21:38:22 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &nums, int target) {
        // write your code here
        sort(nums.begin(),nums.end());
        set<pair<int,int>> st;
        int n=nums.size();
        int l=0,r=n-1;

        int ans=0;
        while(l<r){
            int sum=nums[l]+nums[r];
            if(sum==target)
                st.insert({nums[l],nums[r]});

            if(sum<target)
                l++;
            else
                r--;
        }
        return st.size();
    }
};
