/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : minimizeDistanceToGasStation.cpp
 * @created     : Saturday Sep 18, 2021 02:17:22 IST
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

    bool isPossible(vector<int> &nums,int k,double gap){
        int count=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            int val=(int)((nums[i+1]-nums[i])/gap);
            count+=val;
        }
        return count<=k;
    }

    double minmaxGasDist(vector<int>& stations, int k) {
        //we will use binary search to find the smallest possible value of distance
        int n=stations.size();
        double l=0,r=stations[n-1]-stations[0];

        //while the distance gap between the adjacent values is < 1e-6
        double ans=INT_MAX;
        while(r-l>1e-6){
            double m=l+(r-l)/2;
            //check if can have k stations with this gap
            if(isPossible(stations,k,m)){
                ans=min(ans,m);
                r=m;
            }
            else
                l=m;
        }
        return ans;
    }
};


