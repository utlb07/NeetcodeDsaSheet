class Solution {
public:
   int dp[46];
    int fun(int x, int i) {
        if (i == 0)
        {
            return 1;
        }
        if(i<0)
        {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        return dp[i] = fun(x, i - 1) + fun(x, i - 2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return fun(n, n);
    }
};
