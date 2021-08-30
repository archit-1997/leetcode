/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : rangeAdditionII.cpp
 * @created     : Tuesday Aug 31, 2021 05:08:44 IST
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
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row=INT_MAX,col=INT_MAX;

        if(ops.size()==0)
            return m*n;

        for(vector<int> num: ops){
            row=min(row,num[0]);
            col=min(col,num[1]);
        }

        return (row)*(col);
    }
};
