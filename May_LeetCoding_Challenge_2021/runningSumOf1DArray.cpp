class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    int n = nums.size();
    vector<int> v = nums;
    for (int i = 1; i < n; i++)
      v[i] = v[i - 1] + nums[i];
    return v;
  }
};