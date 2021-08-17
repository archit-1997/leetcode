/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : houseRobber.cpp
 * @created     : Tuesday Aug 17, 2021 19:57:45 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int inc=0,exc=0;
        for(int i=0;i<n;i++){
            //we need to store thre max of prev inc,exc
            int tmp=max(inc,exc);
            inc=max(inc,exc+nums[i]);
            exc=tmp;
        }
        return max(inc,exc);
    }
};
