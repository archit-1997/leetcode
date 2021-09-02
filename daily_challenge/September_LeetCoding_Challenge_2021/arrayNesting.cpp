/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : arrayNesting.cpp
 * @created     : Thursday Sep 02, 2021 11:01:14 IST
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

    void solve(vector<int> &nums,int index,vector<int> &vis,int &ans){
        int count=0;
        while(1){
            if(vis[index])
                break;
            vis[index]=1;
            count++;
            index=nums[index];
        }
        ans=max(ans,count);
    }
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
                solve(nums,i,vis,ans);
        }
        return ans;
    }
};
