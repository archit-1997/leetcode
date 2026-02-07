/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : equalTreePartition.cpp
 * @created     : Monday Aug 30, 2021 20:41:47 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

class Solution {
public:

    void findSum(TreeNode* root,long long &sum){
        if(root==NULL)
            return;
        findSum(root->left,sum);
        sum+=root->val;
        findSum(root->right,sum);
    }

    bool isLeaf(TreeNode* root){
        return (root->left==NULL && root->right==NULL);
    }

    int verify(TreeNode* root,long long &sum,bool &ans){
        if(root==NULL)
            return 0;

        if(isLeaf(root))
            return root->val;

        long long ls=verify(root->left,sum,ans);
        long long rs=verify(root->right,sum,ans);
        
        long long l=LONG_MIN,r=LONG_MIN;
        if(root->left)
            l=(sum-ls);
        if(root->right)
            r=(sum-rs);

        if(l!=LONG_MIN && (l==ls))
            ans=true;
        if(r!=LONG_MIN && (r==rs))
            ans=true;

        return (ls+rs+root->val);
    }

    bool checkEqualTree(TreeNode* root) {
        long long sum=0;
        TreeNode* tmp=root;
        findSum(tmp,sum);

        bool ans=false;
        verify(root,sum,ans);
        return ans;
    }
};

