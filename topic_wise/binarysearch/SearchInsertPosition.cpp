/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : searchInsertPosition.cpp
 * @created     : Saturday Aug 28, 2021 22:42:56 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        return ans;
    }
};
