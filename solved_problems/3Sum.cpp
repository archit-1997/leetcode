/*Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++)
        {
            int j=i+1,k=n-1;
            
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum<0)
                   j++;
                else if(sum>0)
                    k--;
                else
                {
                     vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(nums[k]);
                    
                    ans.push_back(res);
                    
                    int front=nums[j],back=nums[k];
                    
                    //setting the duplicate condition
                    while(j<k && front==nums[j])
                        j++;
                    while(j<k && back==nums[k])
                        k--;
                }
                
                
            }
            
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
        }
        
        return ans;
        
    }
};
