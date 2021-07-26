/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : describeThePainting.cpp
 * @created     : Sunday Jul 25, 2021 15:58:16 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long int,long long int> color;
        for(vector<int> v : segments){
            color[v[0]]+=v[2];
            color[v[1]]-=v[2];
        }

        vector<vector<long long>> ans;
        long long int start,end;
        long long int sum=0;
        for(auto it=color.begin();it!=color.end();it++){
            end=it->first;
            if(sum!=0)
                ans.push_back({start,end,sum});
            start=end;
            sum+=it->second;
        }
        return ans;
    }
};

