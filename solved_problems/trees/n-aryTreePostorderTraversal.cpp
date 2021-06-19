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

    void postorder(Node* root,vector<int> &ans){
        if(root==NULL)
            return;

        vector<Node*> children=root->children;
        for(Node* child : children)
            postorder(child,ans);
        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};//
// Created by Archit Singh on 19/06/21.
//

