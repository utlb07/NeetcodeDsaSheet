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
		 int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                
                else{
                    int up = grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else up+=1e9;
                    
                    int left = grid[i][j];
                    if(j>0) left+=dp[i][j-1];
                    else left+=1e9;
                    
                    dp[i][j] = min(up, left);
                }
            }
        }
        
        return dp[m-1][n-1];
        
    }
};