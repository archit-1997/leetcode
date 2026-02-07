/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : bitwiseAndOfNumbers.cpp
 * @created     : Sunday Oct 10, 2021 21:40:50 IST
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
    int rangeBitwiseAnd(int left, int right) {
        while(left<right)
            right=right&(right-1);
        return left&right;
    }
};

