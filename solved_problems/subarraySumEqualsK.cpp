class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    int ans = 0;
    int sum = 0;
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      if (sum == k)
        ans++;
      if (pos[sum - k] > 0)
        ans += pos[sum - k];

      pos[sum]++;
    }

    return ans;
  }
};