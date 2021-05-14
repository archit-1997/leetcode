class Solution {
public:
  bool reorderedPowerOf2(int N) {
    string s = to_string(N);

    sort(s.begin(), s.end());

    do {
      long long int n = stoi(s);
      string rep = to_string(n);
      if (rep.size() == s.size()) {
        if (n && !(n & (n - 1)))
          return true;
      }

    } while (next_permutation(s.begin(), s.end()));
    return false;
  }
};