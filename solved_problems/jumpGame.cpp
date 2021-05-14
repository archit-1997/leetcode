class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int mr = 0;
    if (n == 1)
      return true;
    for (int i = 0; i < n; i++) {
      // if we have gone past this element or we are at this element
      if (i > mr)
        return false;
      if (nums[i] == 0)
        continue;

      mr = max(mr, i + nums[i]);
      if (mr >= n - 1)
        return true;
    }
    return false;
  }
};