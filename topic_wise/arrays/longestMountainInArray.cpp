/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : longestMountainInArray.cpp
 * @created     : Wednesday Aug 04, 2021 11:02:44 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();

        vector<int> left(n,0),right(n,0);

        //filling the left array
        for(int i=1;i<n-1;i++){
           if(arr[i]>arr[i-1]) 
               left[i]=left[i-1]+1;
        }

        //filling the right array
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1])
                right[i]=right[i+1]+1;
        }

        int ans=0;

        for(int i=1;i<n-1;i++){
            if(left[i]!=0 && right[i]!=0)
                ans=max(ans,left[i]+right[i]+1);
        }

        return ans<3?0:ans;
    }
};

