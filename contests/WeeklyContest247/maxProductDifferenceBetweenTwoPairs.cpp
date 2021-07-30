/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : maxProductDifferenceBetweenTwoPairs.cpp
 * @created     : Wednesday Jul 28, 2021 20:02:25 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int a=nums[n-1]*nums[n-2];
        int b=nums[0]*nums[1];
        return a-b;

    }
};
