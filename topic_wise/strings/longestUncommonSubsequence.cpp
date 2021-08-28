/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : longestUncommonSubsequence.cpp
 * @created     : Saturday Aug 28, 2021 09:44:17 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b)
            return -1;
        return max(a.size(),b.size());
    }
};
