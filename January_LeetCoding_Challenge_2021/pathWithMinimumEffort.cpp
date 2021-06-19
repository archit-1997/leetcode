#include <bits/stdc++.h>
#define P pair<int, pair<int, int>>
using namespace std;

class Solution {
public:
  bool isReachable(int x, int y, int row, int col) {
    if (x < 0 || y < 0 || x >= row || y >= col)
      return false;
    return true;
  }

  int minimumEffortPath(vector<vector<int>> &heights) {
    priority_queue<P, vector<P>, greater<P>> q;
    int row = heights.size(), col = heights[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));
    vector<vector<int>> distance(row, vector<int>(col, INT_MAX));

    q.push({0, {0, 0}});
    distance[0][0] = 0;

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while (q.size() > 0) {
      P p = q.top();
      q.pop();
      int dist = p.first;
      int x = p.second.first;
      int y = p.second.second;
      if (!visited[x][y]) {
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++) {
          int x1 = x + dx[i];
          int y1 = y + dy[i];
          if (isReachable(x1, y1, row, col)) {
            int len = max(distance[x][y], abs(heights[x1][y1] - heights[x][y]));
            if (len < distance[x1][y1]) {
              distance[x1][y1] = len;
              q.push({distance[x1][y1], {x1, y1}});
            }
          }
        }
      }
    }
    return distance[row - 1][col - 1];
  }
};