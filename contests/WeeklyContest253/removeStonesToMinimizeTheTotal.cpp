/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : removeStonesToMinimizeTheTotal.cpp
 * @created     : Sunday Aug 08, 2021 08:07:31 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int> q;
        for(int pile:piles)
            q.push(pile);

        while(k--){
            int t=q.top();
            q.pop();
            int fv=t/2;
            t-=fv;
            if(t>0)
                q.push(t);
            if(q.empty())
                break;
        }

        int ans=0;
        while(!q.empty()){
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};
