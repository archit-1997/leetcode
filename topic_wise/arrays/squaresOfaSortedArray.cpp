/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : squaresOfaSortedArray.cpp
 * @created     : Sunday Aug 29, 2021 12:45:31 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            nums[i]=pow(nums[i],2);
        sort(nums.begin(),nums.end());
        return nums;
    }
};
