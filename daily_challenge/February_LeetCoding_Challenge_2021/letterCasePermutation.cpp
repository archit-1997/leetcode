class Solution {
public:
  void findPermutations(int index, string word, string s, vector<string> &ans) {
    int n = s.size();
    if (index >= n) {
      ans.push_back(word);
      return;
    }
    bool pushed = false;
    // check if this is a character
    if (s[index] >= 'a' && s[index] <= 'z') {
      pushed = true;
      int ascii = s[index] - 32;
      word.push_back(char(ascii));
      findPermutations(index + 1, word, s, ans);
    } else if (s[index] >= 'A' && s[index] <= 'Z') {
      pushed = true;
      int ascii = s[index] + 32;
      word.push_back(char(ascii));
      findPermutations(index + 1, word, s, ans);
    }
    if (pushed)
      word.pop_back();
    word.push_back(s[index]);
    findPermutations(index + 1, word, s, ans);
  }

  vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    int n = s.size();

    string word = "";

    findPermutations(0, word, s, ans);

    return ans;
  }
};