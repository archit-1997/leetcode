/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : twoSumGreaterThanTarget.cpp
 * @created     : Thursday Aug 12, 2021 21:34:57 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        // write your code here
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int l=0,r=n-1;
        int ans=0;
        while(l<r){
            if(nums[l]+nums[r]>target){
                ans+=(r-l);
                r--;
            }
            else
                l++;
        }
        return ans;
    }
};
