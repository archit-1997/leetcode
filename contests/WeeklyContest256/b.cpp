/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : b.cpp
 * @created     : Sunday Aug 29, 2021 08:21:17 IST
 */

#include <bits/stdc++.h>
using namespace std;

bool compare(const string &a,const string &b){
    int na=a.size(),nb=b.size();
    if(na==nb){
        for(int i=0;i<na;i++){
            if(a[i]>b[i])
                return true;
            if(a[i]<b[i])
                return false;
        }
        return false;
    }
    return a.size()>b.size();
}

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),compare);
        return nums[k-1];
    }
};
