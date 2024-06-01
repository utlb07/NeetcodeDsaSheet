class Solution
{
    public:
        int dp[12 + 1][10000 + 1];
    int fun(int id, int amount, vector<int> &coins)
    {
        if (id == 0)
        
        {
            if (amount%coins[0]==0)
            {
                return amount / coins[0];
            }
            else
            {
                return 1e9;
            }
        }

        if (dp[id][amount] != -1)
        {
            return dp[id][amount];
        }
        int pick = 1e9;
        if (amount - coins[id] >= 0)
        {
            pick = 1 + fun(id, amount - coins[id], coins);
        }
        int notpick = fun(id - 1, amount, coins);
        return dp[id][amount] = min(pick, notpick);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof(dp));
        int ans = fun(coins.size() - 1, amount, coins);
        return ans >= 1e9 ? -1 : ans;
    }
};