class Solution {
public:
  bool hasAllCodes(string s, int k) {
    if (k >= n)
      return false;
    set<string> st;
    int n = s.size();
    for (int i = 0; i <= n - k; i++) {
      string str = s.substr(i, k);
      st.insert(str);
    }

    int count = pow(2, k);

    if (count == st.size())
      return true;
    else
      return false;
  }
};