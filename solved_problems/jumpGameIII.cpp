class Solution {
public:
  bool isReachable(vector<int> &v, queue<int> &q) {
    int n = v.size();
    vector<int> vis(n, 0);
    while (!q.empty()) {
      int t = q.front();
      q.pop();

      if (v[t] == 0)
        return true;
      vis[t] = 1;
      int front = t + v[t];
      int back = t - v[t];

      if (front < n && !vis[front])
        q.push(front);
      if (back >= 0 && !vis[back])
        q.push(back);
    }

    return false;
  }

  bool canReach(vector<int> &arr, int start) {
    queue<int> q;
    int n = arr.size();
    q.push(start);
    return isReachable(arr, q);
  }
};