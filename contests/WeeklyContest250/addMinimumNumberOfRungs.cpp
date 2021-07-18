#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n=rungs.size();
        int ans=0;
        int prev=0;
        for(int i=0;i<n;i++){
            int diff=rungs[i]-prev;
            if(diff>dist){
                int rem=diff%dist;
                ans+=diff/dist;
                if(rem==0)
                    ans--;
            }
            prev=rungs[i];
        }
        return ans;
    }
};
