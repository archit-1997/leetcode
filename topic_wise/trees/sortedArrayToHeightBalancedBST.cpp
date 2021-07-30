/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : sortedArrayToHeightBalancedBST.cpp
 * @created     : Thursday Jul 29, 2021 10:26:02 IST
 */


#include <bits/stdc++.h>
using namespace std;

void init(){
				freopen("input.txt","r",stdin);
				freopen("output.txt","w",stdout);
}


// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:

    TreeNode* constructTree(TreeNode* root,vector<int> &nums,int low,int high){
        if(low>high)
            return NULL;

        int mid=low+(high-low)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        //populate the left and right part
        newNode->left=constructTree(root,nums,low,mid-1);
        newNode->right=constructTree(root,nums,mid+1,high);
        return newNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        int mid=n/2;
        TreeNode* root=new TreeNode(nums[mid]);

        root->left=constructTree(root,nums,0,mid-1);
        root->right=constructTree(root,nums,mid+1,n-1);

        return root;
    }
};
