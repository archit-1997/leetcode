/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : sumOfBitWiseXORofSubarrays.cpp
 * @created     : Friday Aug 27, 2021 06:18:24 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<int> ans;
        int left=0,right,n=arr.size();

        for(int i=0;i<n;i++ ){
            right=ans.size();
            ans.push_back(arr[i]);

            for(int j=left;j<right;j++){
                int val=ans[j]|arr[i];
                if(ans.back()!=val)
                    ans.push_back(val);
            }
            left=right;
        }

        return set(ans.begin(),ans.end()).size();
    }
};
