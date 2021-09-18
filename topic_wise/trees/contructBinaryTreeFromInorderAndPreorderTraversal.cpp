/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : contructBinaryTreeFromInorderAndPreorderTraversal.cpp
 * @created     : Wednesday Sep 08, 2021 16:07:59 IST
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

    int cur;

    TreeNode* contructTree(int l,int r,unordered_map<int,int> &index,vector<int> &preorder){
        //find the first value between inorder(l-r) which comes in preorder array
        if(l>r)
            return NULL;

        //create a node for the current node in preorder traversal
        TreeNode* node= new TreeNode(preorder[cur]);
        cur++;
        if(l==r)
            return node;

        int m=index[node->val];
        //recur for the left and the right subtree
        node->left=contructTree(l,m-1,index,preorder);
        node->right=contructTree(m+1,r,index,preorder);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //we need to map the index of each value in inorder traversal
        int n=inorder.size();
        unordered_map<int,int> index;
        for(int i=0;i<n;i++)
            index[inorder[i]]=i;

        //we need to construct the tree, solve function returns the root of the tree
        //the root node of the tree
        cur=0;
        TreeNode *root=solve(0,n-1,index,preorder);
        return root;
    }
};
