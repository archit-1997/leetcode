/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : subsetsII.cpp
 * @created     : Tuesday Aug 03, 2021 22:46:38 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void findSubset(vector<int> &nums,vector<int> &tmp, vector<vector<int>> &ans,int index){
        ans.push_back(tmp);
        int n=nums.size();
        for(int i=index;i<n;i++){
            if(i>index && nums[i]==nums[i-1])
                continue;
            tmp.push_back(nums[i]);
            findSubset(nums,tmp,ans,i+1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        findSubset(nums,tmp,ans,0);
        return ans;
    }
};

