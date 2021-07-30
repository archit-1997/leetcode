/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : twoSumClosestToTarget.cpp
 * @created     : Thursday Jul 29, 2021 09:00:15 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(vector<int> &nums, int target) {
        // write your code here
        int n=nums.size();
        sort(nums.begin(),nums.end()); 
        int ans=INT_MAX;
        int l=0,r=n-1;
        while(l<r){
            int sum=nums[l]+nums[r];
            int diff=(target-sum);
            //if found the answer
            if(diff==0)
                    return 0;

            if(abs(diff)<ans)
                ans=abs(diff);

            if(sum<target)
                l++;
            else
                r--;
        }
        return ans;
    }
};
