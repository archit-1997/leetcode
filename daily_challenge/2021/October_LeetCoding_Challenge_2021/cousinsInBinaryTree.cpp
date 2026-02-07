/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : cousinsInBinaryTree.cpp
 * @created     : Saturday Aug 14, 2021 17:00:38 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findHeight(TreeNode* root,int &par,int target){
        if(root==NULL)
            return -1;

        if(root->val==target)
            return 0;

        //we will look for this node in the left subtree : here the parent will be root
        par=root->val;
        int left=findHeight(root->left,par,target);
        if(left!=-1){
            //we have found the node
            return 1+left;
        }
        //not found in the left side, we will look for it on the right side
        par=root->val;
        int right=findHeight(root->right,par,target);
        if(right!=-1)
            return 1+right;

        return -1;


    }

    bool isCousins(TreeNode* root, int x, int y) {
        //we will find the height and the parent of each of the node and then compare the values
        //if root is the given node
        if(root->val==x && root->val==y)
            return false;

        int px=-1;
        int hx=findHeight(root,px,x);

        int py=-1;
        int hy=findHeight(root,py,y);

        return (hx==hy && px!=py);
    }
};

