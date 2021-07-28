/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : countAndSay.cpp
 * @created     : Wednesday Jul 28, 2021 18:52:24 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        int count=1;
        while(count<n){
            string res="";
            int i=0,c;
            int len=s.size();
            while(i<len){
                c=0;
                char ch=s[i];
                while(i<len && s[i]==ch){
                    c++;
                    i++;
                }
                res=res+(char)(c+'0')+ch;
            }
            s=res;
            count++;
        }
        return s;
    }
};
