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

    bool isLeaf(TreeNode *root) {
        return (!root->left && !root->right);
    }

    void leafInorder(TreeNode *root, vector<int> &seq) {
        if (root == NULL)
            return;

        leafInorder(root->left, seq);

        if (isLeaf(root))
            seq.push_back(root->val);

        leafInorder(root->right, seq);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> seq1, seq2;

        leafInorder(root1, seq1);
        leafInorder(root2, seq2);

        if (seq1.size() != seq2.size())
            return false;

        //compare the values
        for (int i = 0; i < seq1.size(); i++) {
            if (seq1[i] != seq2[i])
                return false;
        }

        return true;
    }
};