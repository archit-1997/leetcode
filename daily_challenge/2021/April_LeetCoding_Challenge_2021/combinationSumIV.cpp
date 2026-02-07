class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int r = triangle.size();
    vector<vector<int>> dp(r, vector<int>(r, 0));

    if (r == 0)
      return 0;

    dp[0][0] = triangle[0][0];
    for (int i = 1; i < r; i++) {
      for (int j = 0; j < i; j++) {
        if (j == 0)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      }
    }

    int ans = INT_MAX;
    for (int j = 0; j < r; j++)
      ans = min(ans, dp[r - 1][j]);

    return ans;
  }
};