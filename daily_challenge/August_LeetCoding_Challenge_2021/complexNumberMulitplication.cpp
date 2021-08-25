/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : complexNumberMulitplication.cpp
 * @created     : Wednesday Aug 25, 2021 08:27:48 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        pair<int, int> av = parse(a);
        pair<int, int> bv = parse(b);
        int ra = av.first * bv.first - av.second * bv.second;
        int rb = av.first * bv.second + av.second * bv.first;
        return to_string(ra) + "+" + to_string(rb) + "i";
    }

    pair<int, int> parse(const string& a) {
        int plus = find(a.begin(), a.end(), '+') - a.begin();
        int i = find(a.begin(), a.end(), 'i') - a.begin();
        int ra = stoi(a.substr(0, plus));
        int rb = stoi(a.substr(plus + 1, i - plus));
        return {ra, rb};
    }
};
