class Solution
{
    public:
     int topDown(string& word1,string& word2,int i,int j,vector<vector<int>>& dp){
        if(i>=word1.length())
            return word2.length()-j;
        if(j>=word2.length())
            return word1.length()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        if(word1[i]==word2[j])
            ans=topDown(word1,word2,i+1,j+1,dp);
        else{
            int replaced=1+topDown(word1,word2,i+1,j+1,dp);
            int deleted=1+topDown(word1,word2,i+1,j,dp);
            int inserted=1+topDown(word1,word2,i,j+1,dp);
            ans=min(replaced,min(deleted,inserted));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        if(word1.length()==0)
            return word2.length();
        if(word2.length()==0)
            return word1.length();
          //  int i=0,j=0;
            vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,0));
    for (int i = 0; i <= word1.length(); ++i) {
        for (int j = 0; j <= word2.length(); ++j) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
        }
    }
    return dp[word1.length()][word2.length()];
}

        // for(int j=0;j<word1.length();j++)
        // {
        //     dp[word1.length()][j]=word2.length()-j;
        // }
        // for(int i=0;i<word2.length();i++)
        // {
        //     dp[i][word2.length()]=word1.length()-i;
        // }
        // for(int i=word1.length()-1;i>=0;i--)
        // {
        //     for(int j=word2.length()-1;j>=0;j--)
        //     {
        //         if(word1[i]==word2[j])
        //         {
        //             dp[i][j]=1+dp[i+1][j+1];
        //         }
        //         else
        //         {
        //             dp[i][j]=1+dp[i+1][j];
        //             dp[i][j]=1+dp[i+1][j+1];
        //             dp[i][j]=1+dp[i][j+1];
        //         }
        //     }
        // }
        // return dp[0][0];
    
};