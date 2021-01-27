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
        
        //if the first node is the target node
        if(original ==target)
            return cloned;
        
        queue<TreeNode *> orig, dup;
        
        //left is the original array and right is the cloned array
        orig.push(original);
        dup.push(cloned);
        
        while(!orig.empty()){
            TreeNode *t=orig.front(),*ans=dup.front();
            orig.pop(),dup.pop();
            
            
            if(t==target)
                return ans;
            
            if(t->left){
                orig.push(t->left);
                dup.push(ans->left);
            }
            
            if(t->right){
                orig.push(t->right);
                dup.push(ans->right);
            }
        }
        
        return target;
    }
};
