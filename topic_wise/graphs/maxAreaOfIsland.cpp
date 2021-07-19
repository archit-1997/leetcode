class Solution {
public:

    bool isValid(int x, int y, int row, int col) {
        if (x < 0 || y < 0 || x >= row || y >= col)
            return false;
        return true;
    }

    void dfs(vector <vector<int>> &grid, vector<vector<int>> &visited, int x, int y,int &count) {
        count++;
        visited[x][y] = 1;
        int row = grid.size(), col = grid[0].size();
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (isValid(x1, y1, row, col) && grid[x1][y1] == 1 && !visited[x1][y1])
                dfs(grid, visited, x1, y1,count);
        }
    }

    int maxAreaOfIsland(vector <vector<int>> &grid) {
        int row = grid.size(), col = grid[0].size();
        vector <vector<int>> visited(row, vector<int>(col, 0));
        int ans = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int count=0;
                    dfs(grid, visited, i, j,count);
                    ans=max(ans,count);
                }
            }
        }

        return ans;
    }
};