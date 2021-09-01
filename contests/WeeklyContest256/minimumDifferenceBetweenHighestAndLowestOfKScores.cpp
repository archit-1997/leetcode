/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : a.cpp
 * @created     : Sunday Aug 29, 2021 08:17:31 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        int ans=INT_MAX,n=nums.size();
        for(int i=0;i<n;i++){
            int si=i,ei=i+k-1;
            if(ei>=n)
                break;
            ans=min(ans,nums[si]-nums[ei]);
        }
        return ans;
    }
};
