class Solution {
public:
     int dp[1001][1001];
    int fun(string &s,int i,int j)
    {
        if(i>=j)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            return dp[i][j]=fun(s,i+1,j-1);
        }
        return dp[i][j]=0;
    }
    int countSubstrings(string s) {
        int ans=0;
        int maxlen=INT_MIN;
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        int st=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(fun(s,i,j)==true)
                {
                   ans++;
                }
            }
        }
        return ans;
    }
};