class Solution {
public:
  int countSteps(vector<int> &nums, vector<int> &dp, int index) {
    int n = nums.size();
    if (index >= n - 1)
      return 0;

    if (dp[index] != 10001)
      return dp[index];

    for (int i = index + 1; i <= nums[index] + index; i++)
      dp[index] = min(dp[index], 1 + countSteps(nums, dp, i));

    return dp[index];
  }

  int jump(vector<int> &nums) {
    int n = nums.size();
    // dp[i] indicates min num of steps required to reach n-1 from here

    vector<int> dp(n, 10001);

    return countSteps(nums, dp, 0);
  }
};