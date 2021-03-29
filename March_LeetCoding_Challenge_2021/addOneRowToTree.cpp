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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int d=1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,d});
        
        if(depth==1){
            TreeNode* newNode=new TreeNode(val);
            TreeNode* tmp=root;
            root=newNode;
            root->left=tmp;
            root->right=NULL;
            return root;
        }
        
        while(!q.empty()){
            if(q.front().second==depth-1){
                while(!q.empty() && q.front().second==depth-1){
                    pair<TreeNode*,int> p=q.front();
                    q.pop();
                    TreeNode* t=p.first;
                    //assigning the left node
                    if(t->left==NULL){
                        TreeNode* newNode=new TreeNode(val);
                        t->left=newNode;
                        newNode->left=NULL;
                    }
                    else{
                        TreeNode* newNode=new TreeNode(val);
                        TreeNode* tmp=t->left;
                        t->left=newNode;
                        newNode->left=tmp;
                    }
                    
                    //assigning the right node
                    if(t->right==NULL){
                        TreeNode* newNode=new TreeNode(val);
                        t->right=newNode;
                        newNode->right=NULL;
                    }
                    else{
                        TreeNode* newNode=new TreeNode(val);
                        TreeNode* tmp=t->right;
                        t->right=newNode;
                        newNode->right=tmp;
                    }
                }
            }
            else{
                pair<TreeNode*,int> p=q.front();
                q.pop();
                TreeNode* t=p.first;
                int level=p.second;
                
                if(t->left)
                    q.push({t->left,level+1});
                if(t->right)
                    q.push({t->right,level+1});
            }
        }
        return root;
    }
};