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
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int s=0;
        memset(dp,0,sizeof(dp));
        for(auto &it:arr)
        {
            s+=it;
        }
        int sum=s/2;
        if(s%2!=0)
        {
            return false;
        }
        else
        {
             bool dp[n+1][sum+1];
        for (int i = 0; i < arr.size() + 1; i++) 
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0) {
                    dp[i][j] = false;
                }
                if (j == 0) 
                {
                    dp[i][j] = true;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j-arr[i-1]>=0)
                {
                    dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[arr.size()][sum];
        }
    }
};