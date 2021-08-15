/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : minimumNonZeroProductoftheArrayElements.cpp
 * @created     : Sunday Aug 15, 2021 15:24:33 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int mod=1e9+7;

    long long int modExp(long long int x, long long int n){
        long long int ans=1;
        while(n){
            if(n%2)
                ans=(ans*x)%mod;
            n/=2;
            x=((x%mod)*(x%mod))%mod;
        }
        return ans;
    }

    int minNonZeroProduct(int p) {
        long long int base = (1LL<<p)-2;

        long long int ans=modExp(base,base/2)%mod;

        ans=((ans%mod)*((base+1)%mod)%mod);
        return ans;

    }
};
