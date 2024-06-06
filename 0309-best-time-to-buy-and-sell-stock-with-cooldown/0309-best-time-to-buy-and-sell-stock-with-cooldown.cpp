class Solution {
public:
    int dp[5001][3];
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
        int profit=0;
        if(buy==0)
        {
            profit=max(-prices[id]+fun(prices,id+1,1),fun(prices,id+1,0));
        }
        else
        {
            profit=max(+prices[id]+fun(prices,id+2,0),fun(prices,id+1,1));
        }
      return  dp[id][buy]=profit;
       // return profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return fun(prices,0,0);
    }
};