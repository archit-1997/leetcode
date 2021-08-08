/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : longestIncreasingSubsequence.cpp
 * @created     : Sunday Aug 08, 2021 21:53:16 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            if(index==ans.size())
                ans.push_back(nums[i]);
            else
                ans[index]=nums[i];
        }
        return ans.size();
    }
};
