class Solution
{
public:
    int countVowelStrings(int n)
    {

        vector<vector<int> > dp(5, vector<int>(n + 1, 0));

        //initially for n=1, we will have one character string
        for (int i = 0; i < 5; i++)
            dp[i][1] = 1;

        //a-0
        //e-1
        //i-2
        //o-3
        //u-4
        for (int j = 2; j <= n; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                int val = 0;
                for (int k = 0; k <= i; k++)
                    val += dp[i - k][j - 1];
                dp[i][j] = val;
            }
        }
        int ans = 0;
        for (int i = 0; i < 5; i++)
            ans += dp[i][n];

        return ans;
    }
};