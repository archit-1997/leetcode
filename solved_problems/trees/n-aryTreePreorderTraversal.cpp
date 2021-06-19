/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void preorder(Node *root, vector<int> &ans) {
        if (root == NULL)
            return;

        ans.push_back(root->val);
        vector < Node * > childrens = root->children;

        for (int i = 0; i < childrens.size(); i++)
            preorder(childrens[i], ans);
    }

    vector<int> preorder(Node *root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};//
// Created by Archit Singh on 19/06/21.
//

