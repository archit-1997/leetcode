/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : trappingRainwater.cpp
 * @created     : Monday Aug 02, 2021 20:47:52 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int trap(vector<int>& height) {
        int n=height.size();
        int i=0;
        stack<int> st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[i]>height[st.top()]){
                int index=st.top();
                st.pop();

                //now if the stack is emtpy, then water will flow out, so no water trapped
                if(st.empty())
                    break;

                //find the height
                int h=min(height[i],height[st.top()])-height[index];
                int w=i-st.top()-1;
                ans+=(h*w);
            }
            st.push(i);
        }
        return ans;
    }
};
