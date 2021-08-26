/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : reorderDataInLogFiles.cpp
 * @created     : Thursday Aug 26, 2021 12:13:08 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digLogs, res;
        vector<pair<string, string>> lps;
        for(const auto& s : logs) {
            auto i=s.find(' ');
            if(isalpha(s[i+1]))
                lps.emplace_back(s.substr(0, i), s.substr(i+1));
            else
                digLogs.push_back(s);
        }
        sort(lps.begin(), lps.end(), [](auto& lhs, auto& rhs) {
                return lhs.second < rhs.second || lhs.second==rhs.second && lhs.first < rhs.first;
            }
        );
        for(auto& p : lps)
            res.push_back(p.first+" "+p.second);
        copy(digLogs.begin(), digLogs.end(), back_inserter(res));
        return res;
    }
};
