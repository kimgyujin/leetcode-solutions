class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector <vector<long long int>> dp(m,vector<long long int>(n,1e18));
        dp[0][0] = 1;
        for(long long int i=0;i<m;i++)
        {
            for(long long int j=0;j<n;j++)
            {
                if(i+1<m)
                {
                    long long int cost = dp[i][j] + (i+2)*(j+1);
                    if(!(i+1==m-1 && j==n-1))
                    {
                        cost += waitCost[i+1][j];
                    }
                    dp[i+1][j] = min(dp[i+1][j],cost);
                }
                if(j+1<n)
                {
                    long long int cost = dp[i][j] + (i+1)*(j+2);
                    if(!(i==m-1 && j+1==n-1))
                    {
                        cost += waitCost[i][j+1];
                    }
                    dp[i][j+1] = min(dp[i][j+1],cost);                    
                }
            }
        }
        return dp[m-1][n-1];
    }
};
