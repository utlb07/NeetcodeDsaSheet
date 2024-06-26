class Solution {
public:
    int dp[5002][3];
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
        memset(dp,0,sizeof(dp));
        //return fun(prices,0,0);
        int n=prices.size();
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {

            for(int buy=0; buy<=1; buy++) {
                if(buy==1) {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                }
                else dp[i][buy] = max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
            }
        }
        return dp[0][1];
        
    }
};