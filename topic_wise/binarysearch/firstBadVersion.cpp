/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : firstBadVersion.cpp
 * @created     : Saturday Aug 28, 2021 22:33:57 IST
 */

#include <bits/stdc++.h>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int find(int l,int r){
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(isBadVersion(mid)){
                ans=min(ans,mid);
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
    
    int firstBadVersion(int n) {
        return find(1,n);
    }
};
