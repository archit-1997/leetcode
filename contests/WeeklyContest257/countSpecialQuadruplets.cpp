/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : a.cpp
 * @created     : Sunday Sep 05, 2021 07:55:11 IST
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
    int countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        if((i<j && j<k && k<l)&&( nums[i]+nums[j]+nums[k] )==nums[l]){
                            st.insert({i,j,k,l});
                        }
                    }
                }
            }
        }
        return st.size();
    }
};
