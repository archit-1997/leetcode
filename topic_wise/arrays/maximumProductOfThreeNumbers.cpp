/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : maximumProductOfThreeNumbers.cpp
 * @created     : Friday Aug 27, 2021 10:25:40 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int a=nums[n-1]*nums[n-2]*nums[n-3];
        int b=nums[n-1]*nums[n-2]*nums[0];
        int c=nums[0]*nums[1]*nums[n-1];

        int ans=max(a,max(b,c));

        return ans;

    }
}; 
