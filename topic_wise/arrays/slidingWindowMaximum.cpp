/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : slidingWindowMaximum.cpp
 * @created     : Saturday Jul 31, 2021 21:11:09 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> q;
        //we have to always maintain a decreasing order
        //insert the first element into the queue
        q.push_back(0);
        for(int i=1;i<k;i++){
            while(!q.empty() && nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
        }
    
        //now we have the data for the first k segment
        vector<int> ans;
        ans.push_back(nums[q.front()]);

        for(int i=k;i<n;i++){
            //if the first element is out of range
            if(q.front()<=i-k)
                q.pop_front();

            //now keep on popping from the back until you encounter a valid position
            while(!q.empty() && nums[q.back()]<=nums[i])
                q.pop_back();

            //now push the current index
            q.push_back(i);

            //insert the element at front index into answer
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

