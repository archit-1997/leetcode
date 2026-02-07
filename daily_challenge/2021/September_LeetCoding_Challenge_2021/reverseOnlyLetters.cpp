/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : reverseOnlyLetters.cpp
 * @created     : Wednesday Sep 15, 2021 09:39:29 IST
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
    string reverseOnlyLetters(string s) {
        int n=s.size();
        string tmp="";
        unordered_map<int,int> pos;
        for(int i=0;i<n;i++){
            if((s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z'))
                tmp=tmp+s[i];
            else
                pos[i]=1;
        }
        reverse(tmp.begin(),tmp.end());
        string ans="";
        int index=0;
        for(int i=0;i<n;i++){
            if(pos[i])
                ans=ans+s[i];
            else
                ans=ans+tmp[index++];
        }
        return ans;
    }
};
