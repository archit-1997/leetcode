#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumDeviation(vector<int> &nums) {
    int curMin = INT_MAX;
    priority_queue<int> q;
    for (int n : nums) {
      if (n % 2 == 1)
        n *= 2;
      curMin = min(curMin, n);
      q.push(n);
    }

    int ans = INT_MAX;

    while (1) {
      int num = q.top();
      q.pop();

      ans = min(ans, num - curMin);

      if (num % 2 == 1)
        break;

      curMin = min(curMin, num / 2);
      q.push(num / 2);
    }

    return ans;
  }
};