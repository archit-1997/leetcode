/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : reorganizeString.cpp
 * @created     : Thursday Aug 26, 2021 11:06:59 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>q;

        unordered_map<char,int> count;
        for(char ch:s)
            count[ch]++;

        for(auto it : count)
            q.push({it.second,it.first});

        string ans="";
        while(q.size()>1){
            //we will extract the most two frequent characters and place them accordingly
            pair<int,char> f=q.top();
            q.pop();
            pair<int,char> s=q.top();
            q.pop();

            ans=ans+f.second+s.second;
            if(f.first-1>0)
                q.push({f.first-1,f.second});
            if(s.first-1>0)
                q.push({s.first-1,s.second});
        }
        if(!q.empty()){
            if(q.top().first>1)
                return "";
            else
                ans=ans+q.top().second;
        }
        return ans;
    }
};
