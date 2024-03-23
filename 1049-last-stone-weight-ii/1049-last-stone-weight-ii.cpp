class Solution {
public:
    int dp[3001][3001];
    int fun(int id,vector<int>& stones,int target)
    {
        if(id>=stones.size()||target==0)
        {
            return 0;
        }
        if(dp[target][id]!=-1)
        {
            return dp[target][id];
        }
        int pick=0;
        if(target-stones[id]>=0)
        {
            pick=stones[id]+fun(id+1,stones,target-stones[id]);
        }
        int notpick=fun(id+1,stones,target);
        return dp[target][id]=max(pick,notpick);
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int s=0;
        for(auto i:stones)
        {
            s+=i;
        }
        int ans=fun(0,stones,s/2);
        return s-2*ans;
    }
};