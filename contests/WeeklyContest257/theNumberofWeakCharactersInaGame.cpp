/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : b.cpp
 * @created     : Sunday Sep 05, 2021 14:39:26 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

bool compare(vector<int> &a,vector<int> &b){
    if(a[0]==b[0])
        return a[1]>b[1];
    return a[0]<b[0];
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
        sort(properties.begin(),properties.end(),compare);

        int big=INT_MIN,ans=0;
        for(int i=n-1;i>=0;i--){
            if(properties[i][1]<big)
                ans++;
            big=max(big,properties[i][1]);
        }
        return ans;
    }
};
