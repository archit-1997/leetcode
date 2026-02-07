/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : maxProductOfASplittedBinaryTree.cpp
 * @created     : Monday Aug 30, 2021 20:21:11 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

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

    void findSum(TreeNode* root,long long &sum){
        if(root==NULL)
            return; 
        findSum(root->left,sum);
        sum+=root->val;
        findSum(root->right,sum);
    }

    int findRes(TreeNode* root,long long &ans,long long &sum){
        if(root==NULL)
            return 0;
        
        //do postorder traversal
        long long ls=findRes(root->left,ans,sum);
        long long rs=findRes(root->right,ans,sum);

        //find the left and right result
        long long left=(ls)*(sum-ls);
        long long right=(rs)*(sum-rs);
        ans=max(ans,max(left,right));

        return (ls+rs+root->val);
    }

    int maxProduct(TreeNode* root) {
        long long sum=0;
        TreeNode* tmp=root;
        findSum(tmp,sum);

        long long ans=0;
        findRes(root,ans,sum);
        ans=ans%1000000007;
        return ans;
    }
};
