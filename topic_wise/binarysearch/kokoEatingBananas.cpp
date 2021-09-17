/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : kokoEatingBananas.cpp
 * @created     : Saturday Sep 18, 2021 01:13:16 IST
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

    bool isPossible(vector<int> &nums,int x,int limit){
        //we have to consume all nums in limit time with x at a time
        int n=nums.size(),time=0;
        for(int i=0;i<n;i++){
            int val=nums[i]/x;
            if(nums[i]%x!=0)
                val++;
            time+=val;
        }
        return (time<=limit);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        //sort the pile of bananas
        //min possible k is 1 and max is piles[n-1]

        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(piles,mid,h)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};


