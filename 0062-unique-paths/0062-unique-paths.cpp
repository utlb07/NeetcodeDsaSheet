class Solution
{
    public:
        int fun(int row, int col, vector<vector < int>> &dp, int m, int n)
        {
            if (row >= m || col >= n)
            {
                return 0;
            }
            if (row == m - 1 && col == n - 1)
            {
                return 1;
            }
            if (dp[row][col] != -1)
            {
                return dp[row][col];
            }
            int up = 0, right = 0;
            if (row + 1 <= m - 1)
                up = fun(row + 1, col, dp, m, n);
            if (col + 1 <= n - 1)
                right = fun(row, col + 1, dp, m, n);
            return dp[row][col] = up + right;
        }
    int uniquePaths(int m, int n)
    {
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, 0));
       	//return fun(0,0,dp,m,n);
        for (int i = 0; i < m; i++)
        {
           dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = 1;
        }

        int up = 0, right = 0;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
               dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m - 1][n - 1];
    }
};