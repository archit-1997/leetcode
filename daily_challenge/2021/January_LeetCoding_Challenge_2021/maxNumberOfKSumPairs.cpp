class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    int n = nums.size();
    int ans = 0;
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
      int rem = k - nums[i];
      if (count[rem] > 0) {
        ans++;
        count[rem]--;
      } else
        count[nums[i]]++;
    }
    return ans;
  }
};