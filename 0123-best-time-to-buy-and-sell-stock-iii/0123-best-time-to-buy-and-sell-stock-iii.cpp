class Solution
{
    public:
        int solve(int i, int &n, vector<int> &prices, int k, vector<vector< int>> &dp)
        {
            if (i >= n || k <= 0)
            {
                return 0;
            }
            if (dp[i][k] != -1)
            {
                return dp[i][k];
            }
            int ans1 = solve(i + 1, n, prices, k, dp);
            int ans2 = 0;
            if (k % 2 == 0)
            {
                ans2 = -prices[i] + solve(i + 1, n, prices, k - 1, dp);
            }
            else
            {
                ans2 = prices[i] + solve(i + 1, n, prices, k - 1, dp);
            }
            return dp[i][k] = max(ans1, ans2);
        }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int k = 4;
        vector<vector < int>> dp(n, vector<int> (k + 1, -1));
        return solve(0, n, prices, k, dp);
    }
};