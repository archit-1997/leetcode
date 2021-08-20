/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : secondMinimumNodeInABinaryTree.cpp
 * @created     : Friday Aug 20, 2021 21:18:33 IST
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

    void inorder(TreeNode* root,long long int &first,long long int &second){
        if(root==NULL)
            return;
         inorder(root->left,first,second);
         if(root->val<first){
            second=first;
            first=root->val;
         }
         else if(root->val>first){
            if(root->val<second)
                second=root->val;
         }

         inorder(root->right,first,second);
    }

    int findSecondMinimumValue(TreeNode* root) {
        long long int first=LONG_MAX,second=LONG_MAX;
        //do the inoder traversal of the binary tree and then find the answer
        inorder(root,first,second);

        //if we are not able to find out any second smallest node
        if(second==LONG_MIN)
            return -1;
        return second;
    }
};
