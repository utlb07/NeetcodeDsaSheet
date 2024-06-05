class Solution
{
    public:
        int minDistance(string word1, string word2)
        {
            if (word1.length() == 0)
            {
                return word2.length();
            }
            if (word2.length() == 0)
            {
                return word1.length();
            }
            vector<vector < int>> dp(word1.length() + 1, vector<int> (word2.length() + 1, 0));
            for (int i = 0; i <= word1.length(); ++i)
            {
                dp[i][word2.length()] = word1.length() - i;
            }
            for (int j = 0; j <= word2.length(); ++j)
            {
                dp[word1.length()][j] = word2.length() - j;
            }
            for (int i = word1.length() - 1; i >= 0; --i)
            {
                for (int j = word2.length() - 1; j >= 0; --j)
                {
                    if (word1[i] == word2[j])
                    {
                        dp[i][j] = dp[i + 1][j + 1];
                    }
                    else
                    {
                        int del = 1 + dp[i + 1][j];
                        int repl = 1 + dp[i + 1][j + 1];
                        int ins = 1 + dp[i][j + 1];
                        dp[i][j] = min(del, min(repl, ins));
                    }
                }
            }
            return dp[0][0];
        }
};