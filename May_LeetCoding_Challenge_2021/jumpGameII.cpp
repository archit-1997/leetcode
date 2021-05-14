class Solution {
public:
  int jump(vector<int> &nums) {
    // using dp to solve this problem
    int n = nums.size();
    // vector<int> dp(n,INT_MAX)
    // this will given runtime error as overflow : INT_MAX+1
    vector<int> dp(n, 1001);
    // last argument is the starting index
    // this will min number of jumps required to reach the
    // last index from 0 index
    return solve(nums, dp, 0);
  }

  int solve(vector<int> &nums, vector<int> &dp, int pos) {
    // reached the final pos
    if (pos >= nums.size() - 1)
      return 0;
    // already visited
    if (dp[pos] != 1001)
      return dp[pos];
    // reach all posssible places from this pos
    // recursively calculate for this position
    for (int i = 1; i <= nums[pos]; i++) {
      dp[pos] = min(dp[pos], 1 + solve(nums, dp, pos + i));
    }
    return dp[pos];
  }
};