class Solution {
public:
        int dp[1001][1001];
    // int fun(int i,int j,string &s1, string &s2)
    // {
        // if(i<0||j<0)
        // {
        //     return 0;
        // }
        // if(dp[i][j]!=-1)
        // {
        //     return dp[i][j];
        // }
        // int pick=0;
        // if(s1[i]==s2[j])
        // {
        //     pick=1+fun(i-1,j-1,s1,s2);
        // }
        // int notpick=max(fun(i-1,j,s1,s2),fun(i,j-1,s1,s2));
        // return dp[i][j]=max(pick,notpick);
    //}
      int fun(string &s1, string &s2){
         for(int i=0;i<s1.length()+1;i++){
            for(int j=0;j<s2.length()+1;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<s1.length()+1;i++){
            for(int j=1;j<s2.length()+1;j++){
                if(s1[i-1]==s2[j-1]){
                     dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        //return fun(text1.length()-1,text2.length()-1,text1,text2);
        return fun(text1,text2);
    }
    int minDistance(string word1, string word2) {
        return word1.length()+word2.length()-2*longestCommonSubsequence(word1,word2);
    }
};