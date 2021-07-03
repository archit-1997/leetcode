
class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    int n = nums.size();
    vector<int> v = nums;
    if (n < 3)
      return 0;

    int ans = 0, count = 0, diff;
    for (int i = 1; i < n; i++) {
      if (count == 0) {
        diff = v[i] - v[i - 1];
        count += 2;
      } else {
        if (v[i] - v[i - 1] == diff)
          count++;
        else {
          // add the values which we have till now
          if (count >= 3) {
            int val = (count * (count + 1)) / 2 - (2 * count - 1);
            ans += val;
          }

          // assign a new value to diff
          diff = v[i] - v[i - 1];
          count = 2;
        }
      }
    }
    if (count >= 3) {
      int val = (count * (count + 1)) / 2 - (2 * count - 1);
      ans += val;
    }
    return ans;
  }
};
