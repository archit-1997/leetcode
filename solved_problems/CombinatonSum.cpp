/*Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[


  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

class Solution {
public:
    
    void find(vector<int> &v,vector<vector<int>>& ans,int sum,int i,vector<int> &r)
    {
        if(sum<0)
            return ;
        if(sum==0)
        {
            ans.push_back(r);
            return;
        }
        
        while(i<v.size() && sum-v[i]>=0)
        {
            r.push_back(v[i]);
            find(v,ans,sum-v[i],i,r);//same i pass krta hai bcoz of infinite number of times
            i++;
            r.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        
        vector<int> r;
        
        sort(candidates.begin(),candidates.end());
        
        find(candidates,ans,target,0,r);
        
        return ans;
        
    }
};
