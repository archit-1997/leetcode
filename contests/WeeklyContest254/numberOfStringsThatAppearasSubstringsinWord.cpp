/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : numberOfStringsThatAppearasSubstringsinWord.cpp
 * @created     : Sunday Aug 15, 2021 08:01:00 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int> map;
        for(int i=0;i<patterns.size();i++)
            map[patterns[i]]++;;
        int ans=0;
        int n=word.size();
        set<string>st;
        for(int len=1;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                string str=word.substr(i,len);
                st.insert(str);
            }
        }
        for(auto it=st.begin();it!=st.end();it++){
            ans+=map[*it];
        }

        return ans;
    }
};
