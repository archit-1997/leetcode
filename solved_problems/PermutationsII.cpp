/*Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

class Solution {
public:
    
    void find(vector<int>& nums,int l,int r,set<vector<int>>& s)
    {
        if(l==r)
        {
            s.insert(nums);
            return;
        }
        else
        {
            for(int i=l;i<=r;i++)
            {
                swap(nums[i],nums[l]);
                find(nums,l+1,r,s);
                swap(nums[i],nums[l]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> s;
        
        sort(nums.begin(),nums.end());
        
        find(nums,0,nums.size()-1,s);
        
        vector<vector<int>> ans;
        
        for(auto it=s.begin();it!=s.end();++it)
            ans.push_back(*it);

        return ans;
        
        
        
    }
};
