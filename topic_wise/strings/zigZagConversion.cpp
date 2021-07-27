/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : zigZagConversion.cpp
 * @created     : Tuesday Jul 27, 2021 17:44:50 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        vector<string> v(numRows);
        int index=0;
        int down=1,up=0;
        for(int i=0;i<s.size();i++){
            v[index].push_back(s[i]);
            //if we are going down currently
            if(down){
                index++;
                if(index==numRows){
                    down=0;
                    up=1;
                    index=numRows-2;
                }
            }
            else{
            //we are going up
                index--;
                if(index<0){
                    down=1,up=0;
                    index=1;
                }
        
            }
        }
        string ans="";
        for(int i=0;i<v.size();i++)
            ans=ans+v[i];

        return ans;
    }
};
