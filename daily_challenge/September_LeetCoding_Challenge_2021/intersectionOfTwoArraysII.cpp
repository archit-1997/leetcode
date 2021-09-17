/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : intersectionOfTwoArraysII.cpp
 * @created     : Saturday Sep 18, 2021 00:44:59 IST
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int> ans;

        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++,j++;
            }
            else if(nums1[i]<nums2[j])
                i++;
            else
                j++;
        }
        return ans;
    }
};
