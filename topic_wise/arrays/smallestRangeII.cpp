/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : smallestRangeII.cpp
 * @created     : Saturday Sep 18, 2021 09:32:10 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        //sort the array
        sort(nums.begin(),nums.end());
        int n=nums.size();

        //this is the largest gap that we have right now
        int ans=nums[n-1]-nums[0];
        for(int i=0;i<n-1;i++){
            int h=max(nums[i]+k,nums[n-1]-k);
            int l=min(nums[0]+k,nums[i+1]-k);
            ans=min(ans,h-l);
        }
        return ans;
    }
};
