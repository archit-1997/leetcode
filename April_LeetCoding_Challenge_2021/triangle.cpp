class Solution
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        int r = triangle.size();

        if (r == 0)
            return 0;

        for (int i = 1; i < r; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                    triangle[i][j] += triangle[i - 1][j];
                else if (j == i)
                    triangle[i][j] += triangle[i - 1][j - 1];
                else
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < r; j++)
            ans = min(ans, triangle[r - 1][j]);

        return ans;
    }
};