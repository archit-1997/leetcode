/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : flipStringToMonotoneIncreasing.cpp
 * @created     : Wednesday Aug 11, 2021 08:41:06 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size(),i=0;

        int flips=0,ones=0;
        for(int i=0;i<n;i++){
            //assuming that we already have the optimal solution
            //if we encounter a zero,then we don't do anything as string will already be monotone
            if(s[i]=='1')
                ones++;
            else{
                //we can flip this zero and have all ones, 
                flips++;
            }
            //result will be the min of the two
            flips=min(flips,ones);
        }
        return flips;
    }
};
