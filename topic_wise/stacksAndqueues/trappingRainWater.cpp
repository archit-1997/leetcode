/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : test.cpp
 * @created     : Monday Aug 23, 2021 08:08:37 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),ans=0,i=0;
        stack<int> st;
        
        while(i<n){
            while(!st.empty() && height[i]>height[st.top()]){
                int t=st.top();
                st.pop();

                //if the stack becomes empty, we cannot trap
                if(st.empty())
                    break;

                int h=min(height[i],height[st.top()])-height[t];
                int w=i-st.top()-1;
                ans+=(w*h);
            }
            st.push(i);
        }
        return ans;
    }
};
