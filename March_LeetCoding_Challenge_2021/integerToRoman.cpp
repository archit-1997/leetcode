class Solution {
public:
  string intToRoman(int num) {
    vector<int> integer = {1,  4,   5,   9,   10,  40,  50,
                           90, 100, 400, 500, 900, 1000};
    vector<string> roman = {"I",  "IV", "V",  "IX", "X",  "XL", "L",
                            "XC", "C",  "CD", "D",  "CM", "M"};
    int i = 12;
    string ans = "";
    while (num > 0) {
      int div = num / integer[i];
      num = num % integer[i];
      while (div--)
        ans = ans + roman[i];
      i--;
    }
    return ans;
  }
};