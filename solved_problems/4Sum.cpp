/*Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        int length = nums.size();
        int left,right,targettemp;
        if(length>3){
            sort(nums.begin(),nums.end());
            for(int i=0;i<length-3;++i){
                if(i>0){
                    if(nums[i]==nums[i-1]) continue;
                }
                targettemp = target - nums[i];
                for(int j=i+1;j<length-2;j++){
                    if((j>i+1)){
                        if(nums[j]==nums[j-1]) continue;
                    }
                    left = j+1;
                    right = length-1;
                    while(left<right){
                            if(nums[j]+nums[left]+nums[right]==targettemp){
                            result.push_back({nums[i],nums[j],nums[left],nums[right]});
                            while((left<right)&&(nums[left]==nums[left+1])) left++;
                            while((left<right)&&(nums[right]==nums[right-1])) right--;
                            left++;
                            right--;
                            }
                            if(nums[j]+nums[left]+nums[right]>targettemp) right--;
                            if(nums[j]+nums[left]+nums[right]<targettemp) left++;
                    }
                }
            }
        }
        return result;
    }
};
