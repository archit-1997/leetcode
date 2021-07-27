/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : firstMissingPositive.cpp
 * @created     : Tuesday Jul 27, 2021 15:50:16 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            if(nums[l]<=0)
                swap(nums[l],nums[r--]);
            else
                l++;
        }
        n=l;
        for(int i=0;i<n;i++){
            int val=abs(nums[i]);
            if(val>0 && val<=n){
                nums[val-1]=abs(nums[val-1])*-1;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                return i+1;
        }
        return n+1;

    }
};

