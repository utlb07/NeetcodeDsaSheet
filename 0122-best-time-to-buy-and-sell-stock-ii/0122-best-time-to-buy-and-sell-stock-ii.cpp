class Solution {
public:
    int fun(vector<int>& prices, int id, int buy, vector<vector<int>>& dp) {
        int n=prices.size();
        if (id >=n) {
            return 0;
        }
        if (dp[id][buy] != -1) {
            return dp[id][buy];
        }
        int profit;
        
        if (buy == 0) {
            profit = max(-prices[id] + fun(prices, id + 1, 1, dp), fun(prices, id + 1, 0, dp));
        } else {
            profit = max(prices[id] + fun(prices, id + 1, 0, dp), fun(prices, id + 1, 1, dp));
        }
        
        return dp[id][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        
        vector<vector<int>> dp(n, vector<int>(2, -1)); 
        return fun(prices, 0 ,0, dp);
    }
};
