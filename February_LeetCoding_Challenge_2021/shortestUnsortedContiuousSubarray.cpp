#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    int n = nums.size();

    int big = INT_MIN, small = INT_MAX;

    stack<int> st;

    // find the first element on the right which is out of sequence
    st.push(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < st.top()) {
        while (!st.empty() && nums[i] < st.top())
          st.pop();

        small = min(small, nums[i]);
      }
      st.push(nums[i]);
    }

    // check if the array was already sorted
    if (small == INT_MAX)
      return 0;

    // clearing the stack
    while (!st.empty())
      st.pop();

    // find the first element from the right which is out of sequence
    st.push(nums[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] > st.top()) {
        while (!st.empty() && nums[i] > st.top())
          st.pop();

        big = max(big, nums[i]);
      }
      st.push(nums[i]);
    }

    int leftIndex = -1, rightIndex = -1;
    for (int i = 0; i < n; i++) {
      if (nums[i] > small) {
        leftIndex = i;
        break;
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] < big) {
        rightIndex = i;
        break;
      }
    }

    int ans = rightIndex - leftIndex + 1;
    return ans;
  }
};
