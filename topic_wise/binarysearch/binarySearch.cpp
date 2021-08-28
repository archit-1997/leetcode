/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : binarySearch.cpp
 * @created     : Saturday Aug 28, 2021 22:24:19 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int binarySearch(vector<int> &nums,int l,int r,int target){
        if(l>r)
            return -1;

        int mid=l+(r-l)/2;

        if(nums[mid]==target)
            return mid;

        if(nums[mid]<target)
            return binarySearch(nums,mid+1,r,target);
        else
            return binarySearch(nums,l,mid-1,target);
    }

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binarySearch(nums,0,n-1,target);
    }
};
