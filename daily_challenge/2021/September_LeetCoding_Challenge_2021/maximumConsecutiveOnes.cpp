/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : maximumConsecutiveOnes.cpp
 * @created     : Tuesday Sep 21, 2021 14:13:29 IST
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0,count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)
                count++;
            else{
                ans=max(ans,count);
                count=0;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};
