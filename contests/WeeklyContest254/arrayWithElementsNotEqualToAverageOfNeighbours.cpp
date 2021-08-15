/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : arrayWithElementsNotEqualToAverageOfNeighbours.cpp
 * @created     : Sunday Aug 15, 2021 08:14:32 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        sort(nums.begin(),nums.end());
        //fill the even indices first
        int index=0;
        for(int i=0;i<n;i+=2)
            ans[i]=nums[index++];
        //now fill the odd indices
        for(int i=1;i<n;i+=2)
            ans[i]=nums[index++];
        return ans;
    }
};
