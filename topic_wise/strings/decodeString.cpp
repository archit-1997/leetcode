/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : decodeString.cpp
 * @created     : Thursday Aug 26, 2021 11:53:43 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decode(int &index,string s){
        int count=0;
        string ans="";
        for(;index<s.size();index++){
            char ch=s[index];
            if(ch=='['){
                //we already have some count;
                string res=decode(++index,s);
                for(;count>0;count--)
                    ans=ans+res;
            }
            else if(ch>='0' && ch<='9'){
                count=(count*10)+(ch-'0');
            }
            else if(ch==']')
                return ans;
            else
                ans=ans+ch;
        }
        return ans;
    }

    string decodeString(string s) {
        int index=0;
        return decode(index,s);
    }
};
