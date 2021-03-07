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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        double count=0,sum=0;
        while(q.size()>1){
            TreeNode* t=q.front();
            q.pop();
            if(t==NULL){
                //we have to push the result into the array and reset the count and sum
                double avg=sum/count;
                ans.push_back(avg);
                sum=0,count=0;
                q.push(NULL);
            }
            else{
                sum+=t->val;
                count++;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        double avg=sum/count;
        ans.push_back(avg);
        return ans;        
    }
};