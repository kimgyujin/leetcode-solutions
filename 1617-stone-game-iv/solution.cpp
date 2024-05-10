class Solution {
public:
    bool winnerSquareGame(int n) {
        vector <bool> dp(n+1,false);
        for(int i=1;i<=n;i++)
        {
            for(int j=1; ;j++)
            {
                if(i-(j*j) < 0) break;
                if(dp[i-j*j]==false)
                {
                    dp[i] = true;
                    break;
                }
            }
        }        

        return dp[n];
    }
};
