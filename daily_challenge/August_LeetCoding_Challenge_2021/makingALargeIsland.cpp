/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : makingALargeIsland.cpp
 * @created     : Sunday Aug 01, 2021 21:17:12 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(int i, int j, vector<vector<int>> &grid) {
    int r = grid.size(), c = grid[0].size();
    if (i >= 0 && i < r && j >= 0 && j < c && grid[i][j] == 1)
      return true;
    return false;
  }

  int findIndex(int i, int j, int col) { return i * col + j; }

  int findParent(int x, vector<int> &par) {
    while (par[x] != x) {
      par[x] = par[par[x]];
      x = par[x];
    }
    return x;
  }

  void Union(int a, int b, vector<int> &par, vector<int> &size) {
    int pa = findParent(a, par);
    int pb = findParent(b, par);
    if (size[pa] < size[pb]) {
      // we have to make b as parent of a
      par[pa] = par[pb];
      size[pb] += size[pa];
    } else {
      // we have to make a as parent of b
      par[pb] = par[pa];
      size[pa] += size[pb];
    }
  }

  bool isNotConnected(int a, int b, vector<int> &par) {
    int pa = findParent(a, par);
    int pb = findParent(b, par);
    return pa != pb;
  }

  void makeIsland(int x, int y, vector<vector<int>> &grid, vector<int> &size,
                  vector<int> &par) {
    int r = grid.size(), c = grid[0].size();
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
      int x1 = x + dx[i];
      int y1 = y + dy[i];
      // if this is in range and also a 1
      if (isValid(x1, y1, grid)) {
        int a = findIndex(x, y, c), b = findIndex(x1, y1, c);
        // if both are disconnected, then make a as parent of b
        if (isNotConnected(a, b, par))
          Union(a, b, par, size);
      }
    }
  }

  int largestIsland(vector<vector<int>> &grid) {
    int r = grid.size(), c = grid[0].size();
    // every element is it's own parent
    vector<int> par(r * c);
    // size of every group is 1
    vector<int> size(r * c, 1);
    for (int i = 0; i < (r * c); i++)
      par[i] = i;

    // initially all the elements are marked as not visited
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (grid[i][j] == 1) {
          // make this element as of its adjacent and also update it's size
          makeIsland(i, j, grid, size, par);
        }
      }
    }

    int ans = *max_element(size.begin(), size.end());

    // now we have to traverse over each 0, temporarily make it 1 and count the
    // size of the max island
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (grid[i][j] == 0) {
          vector<int> tpar = par, tsize = size;
          grid[i][j] = 1;
          // make this as island
          makeIsland(i, j, grid, tsize, tpar);
          int index = findIndex(i, j, c);
          ans = max(ans, tsize[index]);
          grid[i][j] = 0;
        }
      }
    }

    return ans;
  }
};
