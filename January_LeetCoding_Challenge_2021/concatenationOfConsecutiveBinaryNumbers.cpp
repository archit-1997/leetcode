#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long int countBits(int n) {
    long long int count = 0;
    while (n != 0) {
      n /= 2;
      count++;
    }
    return count;
  }

  int concatenatedBinary(int n) {
    long long int ans = 1, mod = 1e9 + 7;
    for (int i = 2; i <= n; i++) {
      long long int shift = countBits(i);
      ans = ans << shift;
      ans = ans % mod;
      ans += i;
      ans = ans % mod;
    }
    return ans;
  }
};