/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : maximumAvergeSubtree.cpp
 * @created     : Saturday Sep 04, 2021 17:04:22 IST
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

    vector<int> solve(TreeNode* root,double &ans){
        if(root!=NULL){
            vector<int> l=solve(root->left,ans);
            vector<int> r=solve(root->right,ans);

            double res=((double)(l[0]+r[0]+root->val))/((double)(l[1]+r[1]+1));
            ans=max(ans,res);

            return {l[0]+r[0]+root->val,l[1]+r[1]+1};
        }
        return {0,0};
    }

    double maximumAverageSubtree(TreeNode* root) {
        double ans=0;
        solve(root,ans);
        return ans;
    }
};
