/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : uniqueBinarySearchTreesII.cpp
 * @created     : Friday Sep 03, 2021 09:32:48 IST
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
    
    vector<TreeNode*> buildTree(int l, int r){
        vector<TreeNode*> ans;
        if(l>r)
            return {NULL};

        if(l==r)
            return {new TreeNode(l)};

        
        for(int i=l;i<=r;i++){
            vector<TreeNode*>left=buildTree(l,i-1),right=buildTree(i+1,r);

            for(auto l: left){
                for(auto r : right){
                    ans.push_back(new TreeNode(i,l,r));
                }
            }
        }
        return ans;

    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans=buildTree(1,n);
        return ans;
    }
};
