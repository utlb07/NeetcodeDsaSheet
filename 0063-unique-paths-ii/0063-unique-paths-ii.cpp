class Solution
{
    public:
        int fun(int row, int col, vector<vector < int>> &dp, int m, int n, vector< vector< int>> &grid)
        {
            if (row >= m || col >= n || grid[row][col] == 1)
            {
                return 0;
            }
            if (row == m - 1 && col == n - 1 && grid[row][col] != 1)
            {
                return 1;
            }
            if (dp[row][col] != -1)
            {
                return dp[row][col];
            }
            int up = fun(row + 1, col, dp, m, n, grid);
            int right = fun(row, col + 1, dp, m, n, grid);
            return dp[row][col] = up + right;
        }
    int uniquePathsWithObstacles(vector<vector < int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, 0));
        if(grid[0][0]==1)
        {
            return 0;
        }
       		//return fun(0,0,dp,m,n,grid);
    
        // for (int i = 0; i < m; i++)
        // {
        //     if (grid[i][0]==0)
        //     {
        //         dp[i][0] = 1;
        //     }
        //     else
        //     {
        //         dp[i][0] = 0;
        //     }
        // }
        // for (int j = 0; j < n; j++)
        // {
        //     if (grid[0][j]== 0)
        //     {
        //         dp[0][j] = 1;
        //     }
        //     else
        //     {
        //         dp[0][j] = 0;
        //     }
        // }

     //   int up = 0, right = 0;
        dp[0][0]=1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                 if(i==0 && j==0) continue;
                 if(grid[i][j]==0){
                    int up=0;
                    int left=0;
                    
                    if(i-1>=0){
                        up=dp[i-1][j];
                    }
                    if(j-1>=0){
                        left=dp[i][j-1];
                    }
                      dp[i][j]=up+left;
                 }
                    
            }
        }
        return dp[m - 1][n - 1];
    }
};