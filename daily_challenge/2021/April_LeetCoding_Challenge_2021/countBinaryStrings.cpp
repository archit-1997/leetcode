class Solution {
public:
  int countBinarySubstrings(string s) {
    int n = s.size();
    vector<int> count;

    int i = 0, c = 1;
    while (i < n) {
      while (i + 1 < n && s[i] == s[i + 1]) {
        i++;
        c++;
      }
      count.push_back(c);
      i++;
      c = 1;
    }
    int ans = 0;
    for (int i = 0; i < count.size() - 1; i++) {
      int val = min(count[i], count[i + 1]);
      ans += val;
    }

    return ans;
  }
};