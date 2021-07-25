/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : longestNumberAfterMutatingSubstring.cpp
 * @created     : Sunday Jul 25, 2021 18:35:31 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n=num.size();
        bool changed=false;
        for(int i=0;i<n;i++){
            //we need to find the first integer where change is giving higher value
            int curVal=num[i]-'0';
            if(change[curVal]>curVal){
                //our substring will start from here
                while(i<n && change[num[i]-'0']>=(num[i]-'0')){
                    changed=true;
                    num[i]=char(change[num[i]-'0']+'0');
                    i++;
                }
                if(changed)
                    break;
            }
        }
        return num;
    }
};
