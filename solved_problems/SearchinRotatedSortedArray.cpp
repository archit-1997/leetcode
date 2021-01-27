/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1*/

class Solution {
public:
    
    int find(vector<int> v,int l,int h,int key)
    {
        if(l>h)
            return -1;
        
        int m=(l+h)/2;
        
        if(v[m]==key)
            return m;
        
        if(v[l]<=v[m])   
        {
            if(key>=v[l] && key<=v[m])
                return find(v,l,m-1,key);
            
            return find(v,m+1,h,key);
        }
        
        if(key>=v[m] && key<=v[h])
            return find(v,m+1,h,key);
        
        return find(v,l,m-1,key);
        
    }
    
    int search(vector<int>& nums, int target) {
        
        int ans=find(nums,0,nums.size()-1,target);
        
        return ans;
        
    }
};
