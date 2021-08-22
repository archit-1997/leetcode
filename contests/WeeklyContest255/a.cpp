/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : a.cpp
 * @created     : Sunday Aug 22, 2021 07:59:02 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGcd(int a,int b){
        if(b==0)
            return a;
        return findGcd(b,a%b);
    }

    int findGCD(vector<int>& nums) {
        int big=*max_element(nums.begin(),nums.end());
        int small=*min_element(nums.begin(),nums.end());

        int ans=findGcd(big,small);

        return ans;
    }
};
