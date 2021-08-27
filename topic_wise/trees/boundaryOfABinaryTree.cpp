/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : boundaryOfABinaryTree.cpp
 * @created     : Friday Aug 27, 2021 07:55:46 IST
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
 
class Solution {
public:

    bool isLeaf(TreeNode* root){
        return (root->left==NULL && root->right==NULL);
    }

    void printLeft(TreeNode* root,vector<int> &left){
        if(root==NULL || isLeaf(root))
            return;
        left.push_back(root->val);
        if(root->left)
            printLeft(root->left,left);
        else
            printLeft(root->right,left);
    }
    void printRight(TreeNode* root,vector<int> &right){
        if(root==NULL || isLeaf(root))
            return;
        right.push_back(root->val);
        if(root->right)
            printRight(root->right,right);
        else
            printRight(root->left,right);
    }
    void printLeaves(TreeNode* root,vector<int> &leaves){
        if(root==NULL)
            return;
        if(isLeaf(root)){
            leaves.push_back(root->val);
            return;
        }
        printLeaves(root->left,leaves);
        printLeaves(root->right,leaves);
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;

        ans.push_back(root->val);
        if(isLeaf(root))
            return ans;

        vector<int> left,leaves,right;

        printLeft(root->left,left);
        printLeaves(root->left,leaves);
        printLeaves(root->right,leaves);
        printRight(root->right,right);
        reverse(right.begin(),right.end());

        for(int num: left)
            ans.push_back(num);

        for(int num: leaves)
            ans.push_back(num);

        for(int num: right)
            ans.push_back(num);

        return ans;

    }
};
