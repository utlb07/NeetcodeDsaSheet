class Solution {
public:
    int dp[201][10001];
bool fun(int id,int s,vector<int>&arr)
{
    if(id>=arr.size())
    {
        return 0;
    }
    if(id==arr.size()-1&&arr[id]==s||s==0)
    {
        return true;
    }
    if(dp[id][s]!=-1)
    {
        return dp[id][s];
    }
    int take=0;
    if(s-arr[id]>=0)
    {
        take=fun(id+1,s-arr[id],arr);
    }
    int nottake=fun(id+1,s,arr);
    return dp[id][s]=take||nottake;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        memset(dp,-1,sizeof(dp));
        for(auto &it:nums)
        {
            s+=it;
        }
        int target=s/2;
        if(s%2!=0)
        {
            return false;
        }
        else
        {
            return fun(0,target,nums);
        }
    }
};