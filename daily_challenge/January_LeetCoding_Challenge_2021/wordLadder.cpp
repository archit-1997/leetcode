class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

    // first we find all the possible intermediate strings of the given word
    unordered_map<string, vector<string>> dict;

    int n = wordList.size();

    // checking the possibility of the solution
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (wordList[i] == endWord) {
        flag = 1;
        break;
      }
    }

    if (flag == 0)
      return 0;

    for (int i = 0; i < n; i++) {
      // we need to find the intermediate strings of the curr string
      for (int j = 0; j < wordList[i].size(); j++) {
        string rep = wordList[i];
        rep[j] = '*';
        dict[rep].push_back(wordList[i]);
      }
    }
    unordered_map<string, int> vis;
    queue<pair<string, int>> q;

    q.push({beginWord, 1});
    vis[beginWord] = 1;

    while (!q.empty()) {
      pair<string, int> p = q.front();
      q.pop();

      if (p.first == endWord)
        return p.second;
      // we need to find all generic transformations of the curr word
      for (int i = 0; i < p.first.size(); i++) {
        string rep = p.first;
        rep[i] = '*';

        // we need to find that if this is the intermediate state of any of the
        // words in the list
        if (dict[rep].size() > 0) {
          // we will push all these words with level+1
          vector<string> v = dict[rep];
          for (int j = 0; j < v.size(); j++) {
            if (!vis[v[j]]) {
              vis[v[j]] = 1;
              q.push({v[j], p.second + 1});
            }
          }
        }
      }
    }
    return 0;
  }
};