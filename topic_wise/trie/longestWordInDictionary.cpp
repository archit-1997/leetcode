#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  struct TrieNode {
    TrieNode *child[26];
    bool eow;
  };

  TrieNode *createNode() {
    TrieNode *newNode = new TrieNode();
    for (int i = 0; i < 26; i++)
      newNode->child[i] = NULL;
    newNode->eow = false;
    return newNode;
  }

  void insert(TrieNode *root, string s) {
    int n = s.size();
    TrieNode *cur = root;
    for (int i = 0; i < n; i++) {
      int index = s[i] - 'a';
      if (cur->child[index] == NULL)
        cur->child[index] = createNode();
      cur = cur->child[index];
    }
    cur->eow = true;
  }

  void dfs(TrieNode *root, int cur_len, string ans, int &len, string &res) {
    for (int i = 0; i < 26; i++) {
      if (root->child[i] != NULL && root->child[i]->eow) {
        if (cur_len > len)
          len = cur_len;
        char ch = i + 97;
        ans = ans + ch;
        dfs(root->child[i], cur_len + 1, ans, len, res);
        ans.pop_back();
      }
    }

    // maintain answer for this particular branch
    if (ans.size() > res.size())
      res = ans;
  }

  string longestWord(vector<string> &words) {

    int n = words.size();
    // start building the dictionary
    TrieNode *root = createNode();

    for (int i = 0; i < n; i++) {
      string s = words[i];
      insert(root, s);
    }
    string ans = "", res = "";
    int cur_len = 1, len = -1;
    dfs(root, cur_len, ans, len, res);
    return res;
  }
};

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  Solution s;
  int n;
  cin >> n;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  string ans = s.longestWord(v);
  // cout << "hello";
  cout << ans;

  return 0;
}