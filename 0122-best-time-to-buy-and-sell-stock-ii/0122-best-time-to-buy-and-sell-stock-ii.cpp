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
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for (int ind=n-1; ind>=0; ind--) {
            for (int buy=0; buy<=1; buy++) {
                if (buy) dp[ind][buy] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
                else dp[ind][buy] = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
            }
        }
        return dp[0][1];
    }
};
