/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : plaindromePartitioningII.cpp
 * @created     : Tuesday Aug 10, 2021 06:52:55 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCut(string s) {
    int n = s.size();

    // defining the dp vector
    vector<int> cut(n + 1);
    iota(cut.begin(), cut.end(), -1);

    // loop i defining the center of the palindrome
    for (int i = 0; i < n; i++) {
      // j defining the radius of the palindrome

      // odd length palindromes
      for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++)
        cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j]);

      // even length palindromes
      for (int j = 1; i - j + 1 >= 0 && i + 1 < n && s[i - j + 1] == s[i + j];
           j++)
        cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j + 1]);
    }

    return cut[n];
  }
};
