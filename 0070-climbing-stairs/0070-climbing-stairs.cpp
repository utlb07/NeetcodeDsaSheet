class Solution {
public:
    int fun(int n,vector<int>&dp)
    {
        if(n==0||n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int one=fun(n-1,dp);
        int two=fun(n-2,dp);
        return dp[n]=one+two;
    }
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        // return fun(n,dp);
        if(n==0||n==1)
        {
            return 1;
        }
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};