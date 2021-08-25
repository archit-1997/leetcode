/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : sumOfSquareNumbers.cpp
 * @created     : Wednesday Aug 25, 2021 13:50:07 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int a=0,b=sqrt(c);

        while(a<=b){
            long long int sum=a*a + b*b;
            if(sum==c)
                return true;

            if(sum<c)
                a++;
            else
                b--;
        }
        return false;
    }
};

