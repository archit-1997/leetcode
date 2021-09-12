/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : b.cpp
 * @created     : Sunday Sep 12, 2021 08:02:36 IST
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
    long long interchangeableRectangles(vector<vector<int>>& v) {
        unordered_map<pair<int,int>,int> count;
        int n=v.size();
        for(int i=0;i<n;i++){
            int gcd=__gcd(v[i][0],v[i][1]);
            v[i][0]=v[i][0]/gcd;
            v[i][1]=v[i][1]/gcd;
            pair<int,int> p={v[i][0],v[i][1]};
            count[p]++;
        }
        long long big=0;
        for(auto it=count.begin();it!=count.end();it++){
            long long val=it->second;
            if(big<val)
                big=val;
        }

        long long ans=((big)*(big-1))/2;
        return ans;
    }
};
