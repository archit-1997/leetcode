/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : largestNumber.cpp
 * @created     : Friday Aug 06, 2021 09:39:59 IST
 */

#include <bits/stdc++.h>
using namespace std;

bool compare(const int &a,const int &b){
    string x=to_string(a),y=to_string(b);
    return (x+y)>(y+x);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //if all the numbers are zero, then return 0
        bool zero=true;
        for(int n:nums){
            if(n!=0){
                zero=false;
                break;
            }
        }
        if(zero)
            return "0";
        sort(nums.begin(),nums.end(),compare);
        string ans="";
        for(int n:nums)
            ans=ans+to_string(n);

        return ans;
    }
};

