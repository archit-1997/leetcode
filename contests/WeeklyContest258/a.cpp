/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : a.cpp
 * @created     : Sunday Sep 12, 2021 07:56:06 IST
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
    string reversePrefix(string word, char ch) {
        int n=word.size();
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                string first=word.substr(0,i+1);
                string second=word.substr(i+1);
                reverse(first.begin(),first.end());
                string ans=first+second;
                return ans;
            }
        }
        return word;
    }
};
