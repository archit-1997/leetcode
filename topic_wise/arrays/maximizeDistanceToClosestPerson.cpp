/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : maximizeDistanceToClosestPerson.cpp
 * @created     : Friday Aug 20, 2021 20:03:00 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int prev=0;
        int ans=0;

        //if the first few seats are vacant
        int i=0;
        if(seats[0]!=1){
            //we need to find the point where the seat is becoming 1
            while(i<n && seats[i]==0)
                i++;
            
            //we are sure that there is atleast one person
            ans=i;
            prev=i;
            i++;
        }

        for(;i<n;i++){
            if(seats[i]==1){
                int val=(i-prev)/2;
                ans=max(ans,val);
                prev=i;
            }
        }

        //if last element is also vacant
        if(seats[n-1]!=1){
            ans=max(ans,(n-1-prev));
        }

        return ans;
    }
};
