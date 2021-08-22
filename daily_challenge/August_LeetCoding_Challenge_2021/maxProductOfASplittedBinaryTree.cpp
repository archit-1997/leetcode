/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : maxProductOfASplittedBinaryTree.cpp
 * @created     : Friday Aug 20, 2021 10:42:58 IST
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

    int populateSum(TreeNode* root,unordered_map<int,int> &sum,int pos){
        if(root==NULL)
            return 0;
        
        //finding the sum for the left child
        int left=populateSum(root->left,sum,2*pos+1);
        //finding the sum for the right child
        int right=populateSum(root->right,sum,2*pos+2);

        int totalSum=left+right+root->val;
        sum[pos]=totalSum;
        return totalSum;
    }

    bool isLeaf(TreeNode* root){
        return (root->left==NULL && root->right==NULL);
    }

    int findProduct(unordered_map<int,int> &sum,int index,int totalSum){
        int a=sum[index];
        int b=totalSum-a;

        return a*b;
    }

    void findRes(TreeNode* root,unordered_map<int,int> &sum, int pos,int totalSum,long long int &ans){
        //at a particular root, we can disconnect the left and the right edge
        if(root==NULL || isLeaf(root))
            return;

        //recur for the left and the right subtree
        findRes(root->left,sum,2*pos+1,totalSum,ans);
        findRes(root->right,sum,2*pos+2,totalSum,ans);

        //now finding the max of the left and the right nodes
        int leftVal=findProduct(sum,2*pos+1,totalSum);
        int rightVal=findProduct(sum,2*pos+2,totalSum);

        ans=max(leftVal,rightVal);
    }

    int maxProduct(TreeNode* root) {
        unordered_map<int,int> sum;
        //first we need to store the value of the sum of the nodes
        TreeNode* tmp=root;
        populateSum(tmp,sum,0);

        //total sum will be the value of the root
        int totalSum=sum[0];

        long long int  ans=INT_MIN;

        findRes(root,sum,0,totalSum,ans);

        return ans%(int)(1e9+7);
    }
};
