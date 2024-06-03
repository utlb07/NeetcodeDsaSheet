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
        memset(dp,-1,sizeof(dp));
        return fun(n-1,m-1,n,m,s,t);
        
    }
};