class Solution {
public:
  bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {

    // i will store the index for arr
    int i = 0;
    while (i < arr.size()) {
      // find that vector in pieces whose first element is equal
      // to the first element of arr
      int flag = 0, row;
      for (int j = 0; j < pieces.size(); j++) {
        if (pieces[j][0] == arr[i]) {
          row = j;
          flag = 1;
          break;
        }
      }
      if (!flag)
        return false;
      // we have found a number
      // we have to traverse this whole set

      int s = pieces[row].size();
      // we don't have enough elements in the array
      if (i + s > arr.size())
        return false;

      for (int j = 0; j < pieces[row].size(); j++) {
        if (pieces[row][j] != arr[i])
          return false;
        i++;
      }
    }
    return true;
  }
};