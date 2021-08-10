/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : rankTransfromOfAnArray.cpp
 * @created     : Tuesday Aug 10, 2021 08:48:17 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> map;
        int n=arr.size();
        vector<int> tmp(arr.begin(),arr.end());
        sort(tmp.begin(),tmp.end());
        int count=1;
        //now populate the map for tmp
        for(int i=0;i<n;i++){
            if(map.find(tmp[i])==map.end())
                map[tmp[i]]=count++;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[i]=map[arr[i]];
        return ans;
    }
};
