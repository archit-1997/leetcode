/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : diameterOfABinaryTree.cpp
 * @created     : Sunday Aug 15, 2021 20:58:40 IST
 */

#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:

    int findHeight(TreeNode* root,int &ans){
        if(root==NULL)
            return 0;

        int leftHeight=findHeight(root->left,ans);
        int rightHeight=findHeight(root->right,ans);

        //we need to update the diameter
        ans=max(ans,leftHeight+rightHeight+1);

        return 1+max(leftHeight,rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;

        int ans=INT_MIN;
        findHeight(root,ans);
        return ans-1;
    }
};
