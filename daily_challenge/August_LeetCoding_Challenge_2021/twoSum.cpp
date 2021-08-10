/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : twoSum.cpp
 * @created     : Monday Aug 02, 2021 12:31:00 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      int cur = nums[i];
      int rem = target - cur;
      // if rem is present in the array
      if (map.find(rem) != map.end()) {
        ans.push_back(i);
        ans.push_back(map[rem]);
        return ans;
      }
      // if not found
      map[cur] = i;
    }
    return ans;
  }
};
