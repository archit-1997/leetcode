/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : 3SumClosest.cpp
 * @created     : Friday Aug 27, 2021 10:29:20 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0,small=INT_MAX;
        for(int i=n-1;i>=2;i--){
            int l=0,r=i-1;
            while(l<r){
                int sum=nums[l]+nums[r]+nums[i];

                //find the absolute difference
                int diff=abs(sum-target);

                //we have found the min
                if(diff==0)
                    return sum;

                //if we have found a better answer
                if(diff<small){
                    small=diff;
                    ans=sum;
                }
                if(sum<target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};
