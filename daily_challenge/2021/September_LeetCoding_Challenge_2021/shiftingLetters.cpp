/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : shiftingLetters.cpp
 * @created     : Thursday Sep 09, 2021 09:57:12 IST
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
    string shiftingLetters(string s, vector<int>& shifts) {
        long long int n=s.size();

        //finding the size of shift for each number
        for(long long int i=n-2;i>=0;i--)
            shifts[i]=(shifts[i]%26 + shifts[i+1]%26)%26;

        for(int i=0;i<n;i++){
            long long int shiftCount=shifts[i];
            shiftCount%=26;
            long long int index=(s[i]-'a'+1+shiftCount)%26;
            if(index==0)
                s[i]='z';
            else
                s[i]=(char)(96+index);
        }
        return s;
    }
};


