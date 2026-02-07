/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : maximumLengthOfConcatenatedStringsusingUniqueCharacters.cpp
 * @created     : Wednesday Sep 22, 2021 17:51:42 IST
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

    int solve(vector<string> &v,int index, string s){
        unordered_set<char> st(s.begin(),s.end());
        if(st.size()!=s.size())
            return 0;

        int ans=s.size(),n=v.size();
        for(int i=index;i<n;i++)
            ans=max(ans,solve(v,i+1,s+v[i]));

        return ans;
    }

    int maxLength(vector<string>& arr) {
        return solve(arr,0,"");
    }
};
