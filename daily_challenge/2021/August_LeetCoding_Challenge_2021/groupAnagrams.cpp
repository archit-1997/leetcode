/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : groupAnagrams.cpp
 * @created     : Thursday Aug 12, 2021 13:02:18 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> map;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            map[s].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto it:map){
            vector<string> res;
            vector<int> v=it.second;
            for(int i=0;i<it.second.size();i++)
                res.push_back(strs[v[i]]);
            ans.push_back(res);
        }
        return ans;
    }
};
