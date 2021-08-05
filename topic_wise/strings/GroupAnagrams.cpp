/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : groupAnagrams.cpp
 * @created     : Thursday Aug 05, 2021 15:10:14 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        int n=strs.size();

        for(int i=0;i<n;i++){
            string rep=strs[i];
            sort(rep.begin(),rep.end());
            map[rep].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto it=map.begin();it!=map.end();it++)
            ans.push_back(it->second);

        return ans;
    }
};
