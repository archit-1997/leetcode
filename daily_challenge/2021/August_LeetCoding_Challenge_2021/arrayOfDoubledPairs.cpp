/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : arrayOfDoubledPairs.cpp
 * @created     : Wednesday Aug 11, 2021 13:01:49 IST
 */

#include <bits/stdc++.h>
using namespace std;

bool compare(const int &a,const int &b){
    return abs(a)<abs(b);
}

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        int n=arr.size();
        unordered_map<int,int> count;
        for(int i=0;i<n;i++)
            count[arr[i]]++;
        for(int i=0;i<n;i++){
            int val=arr[i];
            //search only if the count exists
            if(count[val]){
                int doub=2*val;
                if(count[doub]<count[val])
                    return false;
                count[doub]-=count[val];
                count[val]=0;
            }
        }
        return true;
    }
};
