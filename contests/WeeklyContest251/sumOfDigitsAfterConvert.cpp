/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : sumOfDigitsAfterConvert.cpp
 * @created     : Sunday Jul 25, 2021 18:28:29 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void perform(string &str){
        //we need to find the sum of digits
        int sum=0;
        for(int i=0;i<str.size();i++){
            int num=str[i]-'0';
            sum+=num;
        }
        str=to_string(sum);
    }

    int getLucky(string s, int k) {
        int n=s.size();
        string str="";
        for(int i=0;i<n;i++){
            int val=s[i]-'a'+1;
            str=str+to_string(val);
        }

        //now we need to do the operation k times
        while(k--){
            //if the length of the string is <=1,return the string
            if(str.size()==1){
                int ans=stoi(str);
                return ans;
            }
            //else perform the function
            perform(str);
        }
        int ans=stoi(str);
        return ans;
    }
};
