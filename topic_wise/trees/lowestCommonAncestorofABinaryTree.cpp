/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : lowestCommonAncestorofABinaryTree.cpp
 * @created     : Saturday Aug 14, 2021 22:03:45 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findPath(TreeNode* root,TreeNode *p,vector<TreeNode*> &path,vector<TreeNode*> &tmp){
        if(root==NULL)
            return;

        if(root==p){
            //this means that we have got our answer
            tmp.push_back(root);
            path=tmp;
            return;
        }

        //we will go to the left subtree
        tmp.push_back(root);
        findPath(root->left,p,path,tmp);
        tmp.pop_back();
        //we will go the right subtree
        tmp.push_back(root);
        findPath(root->right,p,path,tmp);
        tmp.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q)
            return root;

        //find the path from root to p
        vector<TreeNode*> pathp,pathq,v;
        TreeNode* tmp=root;
        findPath(tmp,p,pathp,v);
        tmp=root;
        v.clear();
        findPath(tmp,q,pathq,v);

        int index=0;
        int i=1,j=1;
        while(index<pathp.size() && index<pathq.size()){
            if(pathp[index]->val!=pathq[index]->val)
                return pathp[index-1];
            index++;
        }
        if(pathp.size()<pathq.size())
            return pathp[index-1];
        else
            return pathq[index-1];
    }
};

