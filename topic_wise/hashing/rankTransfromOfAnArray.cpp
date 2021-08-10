/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : rankTransfromOfAnArray.cpp
 * @created     : Tuesday Aug 10, 2021 09:52:27 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v=arr;
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        unordered_map<int,int> map;
        int n=arr.size();
        for(int i=0;i<v.size();i++)
            map[v[i]]=i+1;
        for(int i=0;i<n;i++)
            arr[i]=map[arr[i]];
        return arr;
    }
};
