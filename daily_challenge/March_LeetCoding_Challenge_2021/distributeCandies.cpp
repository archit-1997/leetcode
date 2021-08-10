
class Solution {
public:
  int distributeCandies(vector<int> &candyType) {

    sort(candyType.begin(), candyType.end());

    int n = candyType.size();
    vector<int> v(n, 1);

    for (int i = 1; i < n; i++) {
      if (candyType[i] != candyType[i - 1])
        v[i] = v[i - 1] + 1;
      else
        v[i] = v[i - 1];
    }

    int pos = lower_bound(v.begin(), v.end(), n / 2) - v.begin();
    if (pos == n)
      return v[n - 1];
    else
      return v[pos];
  }
};