/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : guessNumberHigherorLower.cpp
 * @created     : Tuesday Oct 12, 2021 22:06:41 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1,h=n;
        while(l<=h){
            int m=l+(h-l)/2;
            int res=guess(m);
            if(res==0)
                return m;
            else if(res==-1)
                h=m-1;
            else
                l=m+1;
        }
        return l;
    }
};
