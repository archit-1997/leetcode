/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
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
            find(v,ans,sum-v[i],i+1,r);
            while(i+1<v.size() && v[i]==v[i+1])
                i++;
            i++;
            r.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        
        vector<int> r;
        
        sort(candidates.begin(),candidates.end());
        //candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        
        find(candidates,ans,target,0,r);
        
        return ans;
        
    }
};

