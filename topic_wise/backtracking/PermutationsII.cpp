#include <bits/stdc++.h>
using namespace std;

void findPermutations(vector<int> &nums,vector<vector<int>> &ans,int index){
    int n=nums.size();
    if(index==n){
        ans.push_back(nums);
        return;
    }

    set<int> st;
    for(int i=index;i<n;i++){
        //if already swapped with this element, then don't swap again at this index
        if(st.find(nums[i])!=st.end())
            continue;
        st.insert(nums[i]);
        swap(nums[i],nums[index]);
        findPermutations(nums,ans,index+1);
        swap(nums[i],nums[index]);

    }

}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        findPermutations(nums,ans,0);

        return ans;
    }
};

