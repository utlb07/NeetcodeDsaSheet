class Solution {
public:
    int dp[301][5001];
     int fun(vector<int>&coins,int id,int amount)
    {
          if(amount==0)
        {
            return 1;
        }
         if(id==0)
         {
             if(amount%coins[0]==0)
             {
                 return 1;
             }else
             return 0;
         }
         if(dp[id][amount]!=-1)
         {
             return dp[id][amount];
         }
       
        int pick=0;
        if(amount-coins[id]>=0)
        {
            pick=fun(coins,id,amount-coins[id]);
        }
        int notpick=fun(coins,id-1,amount);
        return dp[id][amount]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        return (fun(coins,n-1,amount));
    }
};