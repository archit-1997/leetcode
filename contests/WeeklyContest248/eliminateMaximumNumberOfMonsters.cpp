/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : eliminateMaximumNumberOfMonsters.cpp
 * @created     : Friday Jul 23, 2021 19:08:08 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> time(n,0);

        for(int i=0;i<n;i++){
            int t=dist[i]/speed[i];
            if(dist[i]%speed[i]!=0)
                t++;
            time[i]=t;
        }
        sort(time.begin(),time.end());

        int ans=1;int curTime=0;

        for(int i=1;i<n;i++){
            //charge the gun
            curTime++;
            if(time[i]<=curTime)
                return ans;
            ans++;
        }
        return ans;
    }
};
