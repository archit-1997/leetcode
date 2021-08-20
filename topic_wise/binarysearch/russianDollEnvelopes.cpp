/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : russianDollEnvelopes.cpp
 * @created     : Friday Aug 20, 2021 19:49:02 IST
 */

#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &a,const vector<int> &b){
    if(a[0]==b[0])
        return a[1]>b[1];
    return a[0]<b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        //we will sort on the basis of the first param and in descending on the basis of the second param
        vector<int> ans;
        sort(envelopes.begin(),envelopes.end(),compare);

        for(int i=0;i<n;i++){
            int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
            if(index==ans.size())
                ans.push_back(envelopes[i][1]);
            else
                ans[index]=envelopes[i][1];
        }
        return ans.size();
    }
};
