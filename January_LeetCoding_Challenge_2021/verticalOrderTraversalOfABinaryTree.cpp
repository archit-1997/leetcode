/**
 * Definition for a binary tree node.

 */

#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
  if (a.second == b.second)
    return a.first < b.first;
  return true;
}

class Solution {

private:
  void populate(TreeNode *root, map<pair<int, int>, vector<int>> &hashMap,
                int index, int height) {
    if (root == NULL)
      return;
    pair<int, int> p = {index, height};
    hashMap[p].push_back(root->val);
    if (root->left)
      populate(root->left, hashMap, index - 1, height + 1);
    if (root->right)
      populate(root->right, hashMap, index + 1, height + 1);
  }

public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    map<pair<int, int>, vector<int>> hashMap;
    populate(root, hashMap, 0, 0);
    map<int, vector<int>> tmp;
    for (auto it = hashMap.begin(); it != hashMap.end(); it++) {
      pair<int, int> p = it->first;
      int index = p.first;
      vector<int> v = it->second;
      sort(v.begin(), v.end());
      for (int num : v)
        tmp[index].push_back(num);
    }
    vector<vector<int>> ans;
    for (auto it = tmp.begin(); it != tmp.end(); it++)
      ans.push_back(it->second);
    return ans;
  }
};