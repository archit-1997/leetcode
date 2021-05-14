class Solution {
public:
  vector<int> shortestToChar(string s, char c) {
    int n = s.size();
    vector<int> pos;

    for (int i = 0; i < n; i++) {
      if (s[i] == c)
        pos.push_back(i);
    }

    // we can find the right dist using lower bound
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
      // if we have the given character, then its distance should be 0
      if (s[i] == c)
        continue;

      // find the right distance
      int rightpos = lower_bound(pos.begin(), pos.end(), i + 1) - pos.begin();
      // now find the left pos using the given function
      int leftpos = rightpos - 1;

      int rd = INT_MAX, ld = INT_MAX;
      if (rightpos != pos.size())
        rd = abs(pos[rightpos] - i);
      if (leftpos >= 0)
        ld = abs(i - pos[leftpos]);

      ans[i] = min(ld, rd);
    }

    return ans;
  }
};
