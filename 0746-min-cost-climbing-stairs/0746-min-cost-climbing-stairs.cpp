class Solution {
public:
    int dp[10000];
    int fun(vector<int>& cost,int i)
    {
        if(i>=cost.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int one=cost[i]+fun(cost,i+1);
        int two=cost[i]+fun(cost,i+2);
        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(fun(cost,0),fun(cost,1));
    }
};