/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : nthTribonacciNumber.cpp
 * @created     : Friday Sep 24, 2021 22:40:02 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        vector<int> nums(n+1,0);
        nums[0]=0,nums[1]=1,nums[2]=1;
        for(int i=3;i<=n;i++)
            nums[i]=nums[i-1]+nums[i-2]+nums[i-3];

        return nums[n];

    }
};

