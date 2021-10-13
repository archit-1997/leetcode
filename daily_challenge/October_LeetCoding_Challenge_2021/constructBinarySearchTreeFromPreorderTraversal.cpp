/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : constructBinaryTreeFromPreorderTraversal.cpp
 * @created     : Wednesday Oct 13, 2021 22:11:01 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int i=0;

    TreeNode* bstFromPreorder(vector<int>& preorder,int big=INT_MAX) {
        if(i==preorder.size() || preorder[i]>big)
            return NULL;

        //make the current element the root of the tree
        TreeNode *root=new TreeNode(preorder[i++]);
        root->left=bstFromPreorder(preorder,root->val);
        root->right=bstFromPreorder(preorder,big);
        return root;
    }
};
