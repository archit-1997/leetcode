class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    int n = people.size();
    sort(people.begin(), people.end());
    int l = 0, r = n - 1;
    int ans = 0;
    while (r >= 0 && people[r] == limit) {
      ans++;
      r--;
    }
    if (r < 0)
      return ans;
    if (r == 0)
      return ans + 1;
    while (l <= r) {
      if (l == r)
        return ans + 1;
      if (people[l] + people[r] <= limit) {
        ans++;
        l++;
        r--;
      } else {
        r--;
        ans++;
      }
    }
    return ans;
  }
};