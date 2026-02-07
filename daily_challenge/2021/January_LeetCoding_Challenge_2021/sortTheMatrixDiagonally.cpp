class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    // first sorting the upper half of the matrix column wise
    int row = mat.size(), col = mat[0].size();
    int r = 0, c = 0;
    while (c < col) {
      // r will remain zero for the upper half at the start
      int x = r, y = c;
      // take the elements in a vector
      vector<int> v;
      while (x < row && y < col) {
        v.push_back(mat[x][y]);
        x++, y++;
      }
      sort(v.begin(), v.end());
      x = r, y = c;
      int index = 0;
      while (x < row && y < col) {
        mat[x][y] = v[index];
        index++;
        x++, y++;
      }
      // increment the column number for the next iteration
      c++;
    }
    // sorting the lower half of the matrix row wise
    r = 1, c = 0;
    while (r < row) {
      // c will remain zero for the lower half at the start
      int x = r, y = c;
      // take the elements in a vector
      vector<int> v;
      while (x < row && y < col) {
        v.push_back(mat[x][y]);
        x++, y++;
      }
      sort(v.begin(), v.end());
      x = r, y = c;
      int index = 0;
      while (x < row && y < col) {
        mat[x][y] = v[index];
        index++;
        x++, y++;
      }
      // increment the column number for the next iteration
      r++;
    }

    return mat;
  }
};