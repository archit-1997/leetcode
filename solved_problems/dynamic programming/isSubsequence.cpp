#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool find(string &a,string &b, int i,int j){
        //if we have reached the end 
        if(j==b.size())
            return false;
        //if we have found the string
        if(i==a.size())
            return true;
        if(a[i]==b[j])
            return find(a,b,i+1,j+1);
        else
            return find(a,b,i,j+1);
    }

    bool isSubsequence(string s, string t) {
        return find(s,t,0,0);
    }
};
