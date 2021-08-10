class Solution {
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    int n = heights.size();
    priority_queue<int, vector<int>, greater<int>> q;
    // we start from the first building
    for (int i = 0; i < n - 1; i++) {
      int dif = heights[i] - heights[i - 1];
      if (dif <= 0)
        continue;
      q.push(dif);
      if (q.size() > ladders) {
        bricks -= q.top();
        q.pop();
      }
      if (bricks < 0)
        return i;
    }
    return n - 1;
  }
};