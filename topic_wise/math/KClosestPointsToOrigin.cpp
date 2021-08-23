/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : KClosestPointsToOrigin.cpp
 * @created     : Monday Aug 23, 2021 07:21:55 IST
 */

#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<long long> &a,const vector<long long> &b){
    return a[0]<b[0];
}

class Solution {
public:
    long long findDist(int x,int y){
        long long a = pow(x,2);
        long long b=pow(y,2);

        long long ans=a+b;
        return ans;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        vector<vector<long long>> v;
        int n=points.size();
        for(int i=0;i<n;i++){
            int x=points[i][0],y=points[i][1];
            long long dist=findDist(x,y);
            v.push_back({dist,x,y});
        }
        sort(v.begin(),v.end(),compare);

        for(int i=0;i<k;i++){
            int x=(int)(v[i][1]);
            int y=(int)(v[i][2]);
            ans.push_back({x,y});
        }
        return ans;

    }
};
