class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    int n = nums.size();
    map<int, int> hash;

    vector<int> vis(n + 1, 0);

    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
      hash[nums[i]]++;
      vis[nums[i]] = 1;
    }

    int miss, repeat;

    for (auto it = hash.begin(); it != hash.end(); it++) {
      if (it->second == 2)
        repeat = it->first;
    }

    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0)
        miss = i;
    }

    ans.push_back(repeat);
    ans.push_back(miss);

    return ans;
  }
};