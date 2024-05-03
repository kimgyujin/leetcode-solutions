class Solution {
public:
    int dp[205][205];
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j] = 1e9;
            }
        }
        dp[0][0] = triangle[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j <= i-1)
                {
                    dp[i][j] = min(dp[i][j],triangle[i][j] + dp[i-1][j]);
                }
                if(j-1 >= 0)
                {
                    dp[i][j] = min(dp[i][j],triangle[i][j] + dp[i-1][j-1]);
                }
            }
        }

        int res = 1e9;

        for(int i=0;i<n;i++) res = min(res,dp[n-1][i]);

        return res;
    }
};
