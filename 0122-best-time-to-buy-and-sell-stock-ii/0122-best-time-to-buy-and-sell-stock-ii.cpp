class Solution {
public:
    int dp[30001][2];
    int fun(vector<int>& prices,int id,int buy)
    {
        if(id>=prices.size())
        {
            return 0;
        }
        if(dp[id][buy]!=-1)
        {
            return dp[id][buy];
        }
        int take=0,nottake=0;
        if(buy==0)
        {
            take=max(-prices[id]+fun(prices,id+1,1),fun(prices,id+1,0));
        }
        else
        {
            nottake=max(+prices[id]+fun(prices,id+1,0),fun(prices,id+1,1));
        }
        return dp[id][buy]=max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,0,sizeof(dp));
        //return fun(prices,0,0);
         int n = prices.size();
       // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0]=0;
        for (int ind=n-1; ind>=0; ind--) {
            for (int buy=0; buy<=1; buy++) {
                if (buy) dp[ind][buy] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
                else dp[ind][buy] = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
            }
        }
        return dp[0][1];
    }
};