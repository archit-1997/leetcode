/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : checkIfStringIsAPrefixOfArray.cpp
 * @created     : Sunday Aug 08, 2021 08:01:55 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n=s.size();
        string str="";
        for(string word:words){
            str=str+word;

            if(str==s)
                return true;
            
            if(str.size()>=s.size())
                return false;
        }
        return false;
    }
};
