class Solution {
public:
    // int dp[10000];
    // int fun(vector<int>& nums,int i,int n)
    // {
    //     if(i<0)
    //     {
    //         return 0;
    //     }
    //     if(dp[i]!=-1)
    //     {
    //         return dp[i];
    //     }
    //     int pick=nums[i]+fun(nums,i-2,n);
    //     int notpick=fun(nums,i-1,n);
    //     return dp[i]=max(pick,notpick);
    // }
    int rob(vector<int>& nums) {
       int n=nums.size();
        vector<int>dp(n);
        int pick=0;
        int non_pick=0;
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pick=nums[i];
            if(i>1)   // go for i-2,only when i>1,to avoid negative
              pick+=dp[i-2];
            non_pick=0+dp[i-1];
            
        dp[i]=max(pick,non_pick);
        }
        return dp[n-1];
    }
};