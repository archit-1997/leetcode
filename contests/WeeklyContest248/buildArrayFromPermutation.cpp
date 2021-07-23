/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : buildArrayFromPermutation.cpp
 * @created     : Friday Jul 23, 2021 19:02:57 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[i]=nums[nums[i]];

        return ans;
    }
};
