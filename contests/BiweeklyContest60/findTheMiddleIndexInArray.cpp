/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : a.cpp
 * @created     : Saturday Sep 04, 2021 19:56:45 IST
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
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int num : nums)
            sum+=num;

        int ls=0,rs;
        for(int i=0;i<n;i++){
            rs=sum-(ls+nums[i]);
            if(ls==rs)
                return i;
            ls+=nums[i];
        }
        return -1;
    }
};
