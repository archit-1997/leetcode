#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
  struct TrieNode {
    TrieNode *child[26];
    bool leaf;
  };

  TrieNode *root;

  TrieNode *createNode() {
    TrieNode *newNode = new TrieNode();
    for (int i = 0; i < 26; i++)
      newNode->child[i] = NULL;

    newNode->leaf = false;
    return newNode;
  }

  /** Initialize your data structure here. */
  Trie() {
    // create a new node to hold the dictionary
    root = createNode();
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode *cur = root;
    int n = word.size();
    for (int i = 0; i < n; i++) {
      int index = word[i] - 'a';
      if (cur->child[index] == NULL)
        cur->child[index] = createNode();
      cur = cur->child[index];
    }
    cur->leaf = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode *cur = root;
    int n = word.size();
    for (int i = 0; i < n; i++) {
      int index = word[i] - 'a';
      if (cur->child[index] == NULL)
        return false;
      cur = cur->child[index];
    }

    if (cur != NULL && cur->leaf == true)
      return true;
    return false;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    TrieNode *cur = root;
    int n = prefix.size();
    for (int i = 0; i < n; i++) {
      int index = prefix[i] - 'a';
      if (cur->child[index] == NULL)
        return false;
      cur = cur->child[index];
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */