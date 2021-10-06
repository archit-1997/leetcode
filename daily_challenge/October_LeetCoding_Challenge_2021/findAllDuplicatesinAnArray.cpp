/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : findAllDuplicatesinAnArray.cpp
 * @created     : Wednesday Oct 06, 2021 19:03:51 IST
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
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();

        vector<int> ans;

        for(int i=0;i<n;i++){
            int pos=abs(nums[i]);

            if(nums[pos-1]<0)
                ans.push_back(pos);
            if(nums[pos-1]>0)
                nums[pos-1]*=-1;
        }
        return ans;
    }
};
