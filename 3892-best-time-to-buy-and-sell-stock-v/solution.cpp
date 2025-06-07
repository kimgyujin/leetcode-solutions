class Solution {
public:
    long long int dp[1001][501][3];
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                for(int a=0;a<3;a++)
                {
                    dp[i][j][a] = -1e18;
                }
            }
        }
        dp[0][0][0] = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(dp[i][j][0]!=-1e18)
                {
                    dp[i+1][j][0] = max(dp[i+1][j][0],dp[i][j][0]);
                    if(j+1<=k)
                    {
                        dp[i+1][j+1][1] = max(dp[i+1][j+1][1],dp[i][j][0] - prices[i]);
                        dp[i+1][j+1][2] = max(dp[i+1][j+1][2],dp[i][j][0] + prices[i]);
                    }
                }
                if(dp[i][j][1]!=-1e18)
                {
                    dp[i+1][j][1] = max(dp[i+1][j][1],dp[i][j][1]);
                    dp[i+1][j][0] = max(dp[i+1][j][0],dp[i][j][1] + prices[i]);
                }
                if(dp[i][j][2]!=-1e18)
                {
                    dp[i+1][j][2] = max(dp[i+1][j][2],dp[i][j][2]);
                    dp[i+1][j][0] = max(dp[i+1][j][0],dp[i][j][2] - prices[i]);                    
                }
            }
        }

        long long int res = 0;
        for(int i=0;i<=k;i++) res = max(res,dp[n][i][0]);

        return res;
    }
};
