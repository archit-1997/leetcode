class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {

    int n = nums.size();
    vector<int> ans;
    // check if the element is present in the array or not
    int fpos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (fpos < n && nums[fpos] == target) {
      // the element is present in the array
      int lpos = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
      lpos--;
      ans.push_back(fpos);
      ans.push_back(lpos);
      return ans;
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
  }
};