class Solution {
public:
    int change(int amount, vector<int>& coins) {
          int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        for(int i=0; i<=amount; i++){
            dp[0][i]=(i%coins[0]==0);
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                int nt=dp[i-1][j], tk=0;
                if(j>=coins[i]){
                    tk=dp[i][j-coins[i]];
                }
                dp[i][j]=tk+nt;
            }
        }
        return dp[n-1][amount];
    }
};