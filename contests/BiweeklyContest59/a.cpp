/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : a.cpp
 * @created     : Saturday Aug 21, 2021 20:03:26 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToType(string word) {
        int n=word.size();
        int ans=0;
        //we are initially at a : making the index of a as zero
        int prev=0;
        for(int i=0;i<n;i++){
            int pos=word[i]-'a';
            int clockDistance=abs(pos-prev);
            int antiClockDistance=abs(26-clockDistance);
            ans+=(1+min(clockDistance,antiClockDistance));
            prev=pos;
        }
        return ans;
    }
};
