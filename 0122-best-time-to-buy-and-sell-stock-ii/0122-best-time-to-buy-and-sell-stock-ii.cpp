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
        memset(dp,-1,sizeof(dp));
        return fun(prices,0,0);
    }
};