/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : 3SumClosest.cpp
 * @created     : Tuesday Jul 27, 2021 17:32:22 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=INT_MAX,maxDiff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){
            int l=0,r=i-1;
            while(l<r){
                int sum=nums[l]+nums[r]+nums[i];
                int diff=abs(sum-target);
                if(diff<maxDiff){
                    maxDiff=diff;
                    ans=sum;
                }
                if(sum<=target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};
