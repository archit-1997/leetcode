/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : countGoodNumbers.cpp
 * @created     : Friday Jul 23, 2021 19:48:11 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long int modExpo(long long int x,long long int n,long long int mod){
        if(n==0)
            return 1;
        else if(n%2==0)
            return modExpo((x*x)%mod,n/2,mod);
        else
            return (x*modExpo((x*x)%mod,(n-1)/2,mod))%mod;
    }

    int countGoodNumbers(long long n) {
        //there are 5 even numbers
        //there are 4 prime numbers
        
        long long int mod=1e9+7;
        //counting the indices
        long long int even=(n+1)/2;
        long long int prime=n/2;

        long long int s1=modExpo(5,even,mod);

        long long int s2=modExpo(4,prime,mod);

        long long int ans=(s1*s2)%mod;

        return ans;

    }
};
