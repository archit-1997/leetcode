class Solution {
public:
  int ans = 0;

  // NOTE : here x basically represents the position !!
  void calc(vector<int> &vis, int x, int n) {
    if (x > n) {
      ans++;
      return;
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0 && (i % x == 0 || x % i == 0)) {
        vis[i] = 1;
        // then you can backtrack for i+1
        calc(vis, x + 1, n);
        vis[i] = 0;
      }
    }
  }

  int countArrangement(int n) {

    vector<int> vis(n + 1, 0);

    calc(vis, 1, n);

    return ans;
  }
};