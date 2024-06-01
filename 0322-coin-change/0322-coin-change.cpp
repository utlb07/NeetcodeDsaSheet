class Solution {
public:
int dp[12+1][10000+1];
int fun(int id,int amount,vector<int>&coins)
{
    if(amount==0)
    {
        return 0;
    }
    if(amount<0||id<0)
    {
        return INT_MAX-1;
    }
    if(dp[id][amount]!=-1)
    {
        return dp[id][amount];
    }
    int pick=INT_MAX-1;
    if(amount-coins[id]>=0)
    {
        pick=1+fun(id,amount-coins[id],coins);
    }
    int notpick=fun(id-1,amount,coins);
    return dp[id][amount]=min(pick,notpick);
}
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans=fun(coins.size()-1,amount,coins);
        return ans>=INT_MAX-1?-1:ans;
    }
};