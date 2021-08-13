/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : symmetricTree.cpp
 * @created     : Friday Aug 13, 2021 10:22:41 IST
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

    bool isMirrorTree(TreeNode* r1,TreeNode* r2){
        if(r1==NULL && r2==NULL)
            return true;

        if((r1==NULL && r2!=NULL) || (r1!=NULL && r2==NULL))
            return false;

        return (r1->val== r2->val && isMirrorTree(r1->left,r2->right)&& isMirrorTree(r1->right,r2->left));
    }

    bool isSymmetric(TreeNode* root) {
        return isMirrorTree(root,root);
    }
};
