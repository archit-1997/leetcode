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
    int maxDepth(Node *root) {
        if (root == NULL)
            return 0;
        if (root->children.size() == 0)
            return 1;

        vector < Node * > children = root->children;
        int n = children.size();
        vector<int> height(n, 0);
        for (int i = 0; i < n; i++)
            height[i] = maxDepth(children[i]);
        int maxHeight = *max_element(height.begin(), height.end());
        return maxHeight + 1;
    }
};//
// Created by Archit Singh on 19/06/21.
//

