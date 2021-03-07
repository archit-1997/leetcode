/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        queue<TreeNode*> origin,clone;
        if(original==target)
            return cloned;
        
        origin.push(original);
        clone.push(cloned);

        while(!origin.empty()){
            TreeNode *t==origin.front();
            TreeNode *ans=clone.front();
            if(t==target)
                return ans;
            origin.pop();
            clone.pop();

            if(t->left){
                origin.push(t->left);
                clone.push(ans->left);
            }

            if(t->right){
                origin.push(t->right);
                clone.push(ans->right);
            }
        }
        return NULL;
    }
};