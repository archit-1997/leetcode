/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : kthFactorOfN.cpp
 * @created     : Monday Aug 09, 2021 21:28:05 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        int root=sqrt(n);
        for(int i=1;i<=root;i++){
            if(n%i==0 && --k==0)
                return i;
        }

        //if this is square number, then defintely we need to remove one of the duplicates
        if(root*root==n)
            root--;

        for(int i=root;i>=1;i--){
            if(n%i==0 && --k==0)
                return n/i;
        }

        return -1;
    }
};

