/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : longestIncreasingSubsequence.cpp
 * @created     : Thursday Aug 19, 2021 13:53:35 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            //we find the lower bound of this element
            int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            if(index==ans.size())
                ans.push_back(nums[i]);
            else
                ans[index]=nums[i];
        }
        return ans.size();
    }
};
