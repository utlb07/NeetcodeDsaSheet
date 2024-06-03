class Solution {
public:
    int dp[1001][1001];
    int fun(int i,int j,int n,int m,string &s, string &t)
    {
        if(i<0||j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            dp[i][j]=1+fun(i-1,j-1,n,m,s,t);
        }
        else
        {
            dp[i][j]=max(fun(i-1,j,n,m,s,t),fun(i,j-1,n,m,s,t));
        }
        return dp[i][j];
    }
    int longestCommonSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};