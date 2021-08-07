/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : reverseInteger.cpp
 * @created     : Saturday Aug 07, 2021 08:41:05 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long int num=x;
        bool neg=false;
        if(num<-0)
            neg=true;

        if(neg)
            num*=-1;

        string s=to_string(num);
        std::reverse(s.begin(),s.end());

        long long int res=stoll(s);

        if(neg){
            res*=-1;
            if(res<INT_MIN)
                return 0;
            else
                return (int)res;
        }

        if(res>INT_MAX)
            return 0;
        else
            return (int)res;

    }
};

