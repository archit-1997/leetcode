class Solution {
public:
  int brokenCalc(int x, int y) {
    int ans = 0;
    while (y > x) {
      if (y % 2 == 0)
        y /= 2;
      else
        y++;
      ans++;
    }
    ans += (x - y);
    return ans;
  }
};
