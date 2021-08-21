/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : verticalOrderTraversalOfABinaryTree.cpp
 * @created     : Saturday Aug 21, 2021 08:29:07 IST
 */

#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

bool compare(const pair<int,int> &a,const pair<int,int> &b){
    //if both have the same row,then sort on the value
    if(a.first==b.first)
        return a.second<b.second;
    //both have different row
    return a.first<b.first;
}

class Solution {
public:

    vector<int> fillRes(vector<pair<int,int>> &nums){
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            ans.push_back(nums[i].second);
        return ans;
    }

    void populate(TreeNode* root,map<int,vector<pair<int,int>>> &map,int row,int col){
        if(root==NULL)
             return;

        map[col].push_back({row,root->val});
        //recur for the left and the right subtree
        populate(root->left,map,row+1,col-1);
        populate(root->right,map,row+1,col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;

        map<int,vector<pair<int,int>>> map;
        populate(root,map,0,0);
        for(auto it=map.begin();it!=map.end();it++){
            vector<pair<int,int>> v=it->second;
            sort(v.begin(),v.end(),compare);
            vector<int> res=fillRes(v);
            ans.push_back(res);
        }
        return ans;
    }
};
