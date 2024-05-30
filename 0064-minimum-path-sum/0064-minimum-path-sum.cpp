class Solution {
public:
   int solve(vector<vector<int>>&grid, int i, int j, vector<vector<int>>&dp,int n,int m){

		if(i>=n|| j>=m)
			return 1e9;

		if(i==n-1&&j==m-1)
			return grid[i][j];

		if(dp[i][j]!=-1)
			return dp[i][j];

		return dp[i][j] = grid[i][j] + min(solve(grid, i+1, j, dp,n,m), solve(grid, i, j+1, dp,n,m));   
	}

	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
		return solve(grid, 0, 0, dp,n,m);
    }
};