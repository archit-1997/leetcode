/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : maxSubarraySumWithAtMostOneDeletion.cpp
 * @created     : Thursday Aug 26, 2021 18:37:54 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        int inc=arr[0],exc=min(0,arr[0]);
        int ans=max(inc,exc);

        for(int i=1;i<n;i++){
            //if we are deleting one element
            exc=max(inc,exc+arr[i]);
            inc=max(inc+arr[i],arr[i]);
            ans=max(ans,max(inc,exc));
        }
        return ans;
    }
};
