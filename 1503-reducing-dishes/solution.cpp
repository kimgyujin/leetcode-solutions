int dp[501][501];
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j] = -2e9;
            }
        }
        dp[0][0] = 0;
        int res = 0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(dp[i][j] <= -2e9) continue;
                res = max(res,dp[i][j]);
                if(i+1<=n)
                {
                    dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
                    if(j+1 <= n)
                    {
                        dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j] + (j+1)*satisfaction[i]);
                    }
                }
            }
        }
        
        return res;
    }
};
