#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    vector<pair<int, int>> v;
    for (int i = 0; i < arr.size(); i++) {
      int num = abs(arr[i] - x);
      v.push_back({num, i});
    }
    // sort according to the first value
    sort(v.begin(), v.end());

    // extract the first k elements
    vector<int> ans;
    for (int i = 0; i < k; i++)
      ans.push_back(arr[v[i].second]);

    sort(ans.begin(), ans.end());

    return ans;
  }
};
