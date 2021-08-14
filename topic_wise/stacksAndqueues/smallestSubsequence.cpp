class Solution {
public:
  string smallestSubsequence(string s) {
    stack<char> st;
    int n = s.size();
    unordered_map<char, int> count;
    for (int i = 0; i < n; i++)
      count[s[i]]++;
    int i = 0;
    vector<int> vis(26, 0);
    while (i < n) {
      count[s[i]]--;
      if (vis[s[i] - 'a'] == 0) {
        while (!st.empty() && st.top() >= s[i] && count[st.top()] > 0) {
          vis[st.top() - 'a'] = 0;
          st.pop();
        }
        st.push(s[i]);
        vis[s[i] - 'a'] = 1;
      }
      i++;
    }
    string ans;
    while (!st.empty()) {
      ans = ans + st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
  }
};