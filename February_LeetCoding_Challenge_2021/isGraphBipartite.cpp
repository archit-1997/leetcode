class Solution {
public:
  bool dfs(vector<vector<int>> &graph, vector<int> &color, int x) {
    for (int node : graph[x]) {
      if (color[node] == -1) {
        color[node] = color[x] ^ 1;
        if (!dfs(graph, color, node))
          return false;
      } else if (color[node] == color[x])
        return false;
    }

    return true;
  }

  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++) {
      if (color[i] == -1) {
        color[i] = 1;
        if (!dfs(graph, color, i))
          return false;
      }
    }

    return true;
  }
};