/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : globalAndLocalInversions.cpp
 * @created     : Saturday Aug 21, 2021 16:39:27 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();
        int small=INT_MAX;
        for(int i=n-1;i>=2;i--){
            small=min(small,nums[i]);
            if(nums[i-2]>small)
                return false;
        }
        return true;
    }
};
