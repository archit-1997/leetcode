/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : rotateArray.cpp
 * @created     : Sunday Aug 29, 2021 15:23:30 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        if(k==0)
            return;

        k=n-k;

        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[i]=nums[(i+k)%n];
        nums=ans;
    }
};

