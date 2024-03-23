class Solution {
public:
    int dp[1001][1001];
    int fun(int i,int j,string &s1, string &s2)
    {
        if(i<0||j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int pick=0;
        if(s1[i]==s2[j])
        {
            pick=1+fun(i-1,j-1,s1,s2);
        }
        int notpick=max(fun(i-1,j,s1,s2),fun(i,j-1,s1,s2));
        return dp[i][j]=max(pick,notpick);
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return fun(text1.length()-1,text2.length()-1,text1,text2);
    }
};