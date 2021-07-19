#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void findpermutations(vector<int> &v,vector<vector<int>> &ans, int index){
        if(index==v.size()){
            ans.push_back(v);
            return;
        }
        for(int i=index;i<v.size();i++){
            swap(v[i],v[index]);
            //find permutation of this string
            findpermutations(v,ans,index+1);
            swap(v[i],v[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        findpermutations(nums,ans,0);
        
        return ans;

    }
};


