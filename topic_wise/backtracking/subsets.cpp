/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : subsets.cpp
 * @created     : Wednesday Jul 28, 2021 12:47:45 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void findSubsets(vector<vector<int>> &ans,vector<int> tmp,int index,vector<int> &nums){
        //if we have reached the last index
        if(index==nums.size()){
            ans.push_back(tmp);
            return;
        }

        //exclude this element
        findSubsets(ans,tmp,index+1,nums);
        //include the element at index
        tmp.push_back(nums[index]);
        findSubsets(ans,tmp,index+1,nums);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> tmp;
        findSubsets(ans,tmp,0,nums);
        return ans;
    }
};
