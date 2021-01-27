/*Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]  */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans;
        
        if(binary_search(nums.begin(),nums.end(),target))
        {
            int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            int r=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
            
            ans.push_back(l);
            ans.push_back(r);
            
            return ans;
            
            
        }
        else
        {
            ans.push_back(-1);
            ans.push_back(-1);
            
            return ans;
        }
        
    }
};
