class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n == 0)
      return 0;
    int start = 0, end = 0;
    int ans = INT_MIN;
    unordered_map<char, int> hash;

    for (int i = 0; i < n; i++) {
      hash[s[i]]++;
      if (hash[s[i]] == 1)
        continue;
      else {
        end = i - 1;
        int len = end - start + 1;
        ans = max(ans, len);
        while (hash[s[i]] > 1) {
          hash[s[start]]--;
          start++;
        }
      }
    }
    ans = max(ans, n - start);
    return ans;
  }
};