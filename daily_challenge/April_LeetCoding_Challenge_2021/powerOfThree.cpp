class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n <= 0)
      return false;

    int exp = (int)(log10(n) / log10(3));
    int res = pow(3, exp);

    return (res == n);
  }
};