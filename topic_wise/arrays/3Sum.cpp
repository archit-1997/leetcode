/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : 3Sum.cpp
 * @created     : Wednesday Jul 28, 2021 08:03:39 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=n-1;
        while(i>=2){
            int l=0,r=i-1,sum=0;
            while(l<r){
                sum=nums[l]+nums[r]+nums[i];

                if(sum==0){
                    //this is a valid sum
                    ans.push_back({nums[l],nums[r],nums[i]});
                    
                    //move l and r till the moment numbers are same
                    while(l+1<r && nums[l]==nums[l+1])
                        l++;
                    while(r-1>l && nums[r]==nums[r-1])
                        r--;
                }
                
                if(sum<=0)
                    l++;
                else
                    r--;
            }
            //move i
            while(i-1>=0 && nums[i]==nums[i-1])
                i--;
            i--;
        }
        return ans;
    }
};

