/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : maximumCompatibilityScoreSum.cpp
 * @created     : Sunday Jul 25, 2021 18:55:48 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
            vector<int>pos;
            for(int i=0;i<students.size();i++) pos.push_back(i);
            int ans=0;
            do
            {
                int temp=0;
                for(int i=0;i<pos.size();i++)
                for(int j=0;j<students[0].size();j++)
                if(students[pos[i]][j]==mentors[i][j])
                temp++;
                
                ans=max(ans,temp);
            }while(next_permutation(pos.begin(),pos.end()));
            return ans;
    }
};
