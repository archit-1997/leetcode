/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : addStrings.cpp
 * @created     : Monday Aug 09, 2021 18:06:50 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        int n1=num1.size(),n2=num2.size();
        int i=0,j=0;
        int carry=0;
        while(i<n1 || j<n2){
            int v1=0,v2=0;
            if(i<n1){
                v1=num1[i]-'0';
                i++;
            }
            if(j<n2){
                v2=num2[j]-'0';
                j++;
            }

            int sum=v1+v2+carry;
            int res=sum%10;
            carry=sum/10;
            ans=ans+to_string(res);
        }
        if(carry)
            ans=ans+to_string(carry);

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
