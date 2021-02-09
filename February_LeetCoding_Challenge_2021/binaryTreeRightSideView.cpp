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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(NULL);
        
        while(q.size()>1){
            TreeNode* f=q.front();
            ans.push_back(f->val);
            //now we will start printing the 
            while(q.front()!=NULL){
                TreeNode* t=q.front();
                q.pop();
                if(t->right)
                    q.push(t->right);
                if(t->left)
                    q.push(t->left);
            }
            q.push(NULL);
            //pop the NULL at the beginning
            q.pop();
        }
        return ans;
        
    }
};
