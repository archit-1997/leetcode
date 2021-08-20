/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : maximumUnitsOnATruck.cpp
 * @created     : Friday Aug 20, 2021 21:11:49 IST
 */

#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &a,const vector<int> &b){
    if(a[1]==b[1])
        return a[0]>b[0];
    return a[1]>b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        //sort the boxes
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int ans=0;
        for(int i=0;i<n;i++){
            if(truckSize>=boxTypes[i][0]){
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
                truckSize-=boxTypes[i][0];
            }
            else{
                ans+=(truckSize*boxTypes[i][1]);
                return ans;
            }
        }
        return ans;
    }
};
