class Solution {
public:
  bool checkPossibility(vector<int> &N) {
    int n = N.size();
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
      if (N[i] > N[i + 1]) {
        count++;
        if (count > 1)
          return false;
        // check for yaby case
        if (i - 1 >= 0 && i + 2 < n && N[i - 1] > N[i + 1] && N[i + 2] < N[i])
          return false;
      }
    }
    return true;
  }
};