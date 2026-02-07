#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
  TrieNode() {}

  unordered_map<int, TrieNode *> child;
  map<int, int> hash;
};

class Trie {
public:
  TrieNode *root;

  Trie() { root = new TrieNode(); }

  void insert(string s, int value) {
    TrieNode *cur = root;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int index = s[i] - 'a';
      if (cur->child[index] == NULL)
        cur->child[index] = new TrieNode();
      cur->hash[index] = value;
      cur = cur->child[index];
    }
  }

  int search(string s) {
    TrieNode *cur = root;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int index = s[i] - 'a';
      if (cur->child[index] == NULL)
        return -1;
      if (i == n - 1)
        return cur->hash[index];
      cur = cur->child[index];
    }
    return -1;
  }
};

class WordFilter {
public:
  Trie *trie;

  vector<string> generateHashedWords(string word) {
    vector<string> ans;
    int n = word.size();
    for (int i = n - 1; i >= 0; i--) {
      string str = word.substr(i, n - i);

      string tmp = str + '}' + word;
      ans.push_back(tmp);
    }
    return ans;
  }

  void insertWordsInTrie(vector<string> &words) {
    int n = words.size();
    for (int i = 0; i < n; i++) {
      string word = words[i];
      vector<string> combinations = generateHashedWords(word);
      for (string s : combinations)
        trie->insert(s, i);
    }
  }

  WordFilter(vector<string> &words) {
    trie = new Trie();
    insertWordsInTrie(words);
  }

  int f(string prefix, string suffix) {
    // we will search in the dictionary
    // find the index of elements that start with prefix
    string searchString = suffix + '}' + prefix;
    return trie->search(searchString);
  }
};

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }

  WordFilter *w = new WordFilter(v);
  string pre, suf;
  cin >> pre >> suf;
  return w->f(pre, suf);
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */