class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    int sum = 0, n = nums.size();
    sum = accumulate(nums.begin(), nums.end(), sum);
    int target = sum - x;
    if (sum == x)
      return n;
    // we have to find the max size subarray with given sum
    int len = 0;
    unordered_map<int, int> pos;
    int csum = 0;
    for (int i = 0; i < n; i++) {
      csum += nums[i];
      if (csum == target)
        len = max(len, i + 1);
      if (pos.find(csum - target) != pos.end()) {
        int clen = i - pos[csum - target];
        len = max(len, clen);
      }
      pos[csum] = i;
    }
    if (len == 0)
      return -1;
    return n - len;
  }
};