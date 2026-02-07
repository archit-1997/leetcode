/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : jumpGame.cpp
 * @created     : Sunday Oct 03, 2021 16:33:46 IST
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

    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,0);
        
        int mr=0;
        for(int i=0;i<n;i++){
            //find the termintaing condition
            if(i>mr)
                return false;

            //max point where we can reach from here
            mr=max(mr,nums[i]+i);
            if(mr>=n-1)
                return true;

        }
        return false;
    }
};
