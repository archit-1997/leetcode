/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : nextGreaterElementI.cpp
 * @created     : Monday Aug 02, 2021 07:10:22 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> findNextGreater(vector<int> &nums,int n){
        vector<int> ans(n,-1);
        stack<int> st;
        st.push(0);

        for(int i=1;i<n;i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //first find the next greater element for all the values in nums2
        int n2=nums2.size();
        vector<int> nextGreater=findNextGreater(nums2,n2);

        //map to store the indices of nums2
        unordered_map<int,int> indices;
        for(int i=0;i<n2;i++)
            indices[nums2[i]]=i;
        
        vector<int> ans;
        int n1=nums1.size();
        for(int i=0;i<n1;i++){
            int val=nums1[i];
            //find the index of val in nums[2];
            int index=indices[nums1[i]];
            
            int res=nextGreater[index]==-1?-1:nums2[nextGreater[index]];
            ans.push_back(res);
        }
        return ans;
    }
};


