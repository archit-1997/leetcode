bool compare(pair<int, int> &a, pair<int, int> &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    int row = mat.size(), col = mat[0].size();
    vector<pair<int, int>> v(row);
    // count the number of soilders in every row
    for (int i = 0; i < row; i++) {
      int count = 0;
      for (int j = 0; j < col; j++) {
        if (mat[i][j] == 0)
          break;
        count++;
      }
      v[i] = {count, i};
    }

    sort(v.begin(), v.end(), compare);

    vector<int> ans;
    for (int i = 0; i < k; i++)
      ans.push_back(v[i].second);

    return ans;
  }
};