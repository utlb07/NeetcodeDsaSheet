class Solution {
public:
    int dp[10000];
    int fun(vector<int>& nums,int i,int n)
    {
        if(i<0)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int pick=nums[i]+fun(nums,i-2,n);
        int notpick=fun(nums,i-1,n);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return fun(nums,n-1,n);
    }
};