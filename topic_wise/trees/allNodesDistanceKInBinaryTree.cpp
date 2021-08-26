/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : allNodesDistanceKInBinaryTree.cpp
 * @created     : Thursday Aug 26, 2021 12:59:25 IST
 */

#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    
    void findPath(TreeNode* root,TreeNode* target,vector<TreeNode*> &path,vector<TreeNode*> &tmp){
        if(root==NULL)
            return;

        tmp.push_back(root);
        //if we have found the target node
        if(root==target){
            path=tmp;
            return;
        }

        //we need to go to the left part
        findPath(root->left,target,path,tmp);
        findPath(root->right,target,path,tmp);

        tmp.pop_back();

    }

    void printNodesAtLevelK(TreeNode* root,int k,vector<int> &ans,TreeNode* blocker){
        if(root==NULL || k<0)
            return;

        if(root==blocker)
            return;

        if(k==0){
            ans.push_back(root->val);
            return;
        }
        //recur for the left and the right subtree
        printNodesAtLevelK(root->left,k-1,ans,blocker);
        printNodesAtLevelK(root->right,k-1,ans,blocker);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //first we need to find the path from root to k
        vector<TreeNode*> path;
        vector<TreeNode*> tmp;
        TreeNode* t=root;
        findPath(t,target,path,tmp);
        reverse(path.begin(),path.end());
        
        vector<int> ans;
        for(int i=0;i<path.size();i++){
            TreeNode* blocker=NULL;
            if(i>=1)
                blocker=path[i-1];
            printNodesAtLevelK(path[i],k-i,ans,blocker);
        }
        return ans;
    }
};
