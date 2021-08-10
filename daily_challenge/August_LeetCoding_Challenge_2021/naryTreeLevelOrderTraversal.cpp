/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : naryTreeLevelOrderTraversal.cpp
 * @created     : Friday Aug 06, 2021 20:20:52 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    queue<Node *> q;
    vector<vector<int>> ans;
    if (root == NULL)
      return ans;
    if (root->children.size() == 0) {
      ans.push_back({root->val});
      return ans;
    }

    q.push(root);
    while (!q.empty()) {
      int s = q.size();
      vector<int> tmp;
      while (s--) {
        Node *t = q.front();
        tmp.push_back(t->val);
        q.pop();

        for (int i = 0; i < t->children.size(); i++)
          q.push(t->children[i]);
      }
      ans.push_back(tmp);
    }
    return ans;
  }
};
