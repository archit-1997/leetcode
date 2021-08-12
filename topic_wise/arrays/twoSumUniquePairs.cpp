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
        int n=nums.size();
        int ans=0;
        for(int r=n-1;r>=1;r--){
            int l=r-1;
            while(l>=0 && nums[l]+nums[r]>target)
                l--;
            if(l>=0)
                ans+=(l+1);
        }
        return ans;

    }
};
