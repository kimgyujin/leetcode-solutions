class Solution {
public:
    const long long int MOD = 1e9 + 7;
    long long int dp[500][500][2];
    int n,m;
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        long long int res = 0;
        
        memset(dp,0,sizeof(dp));

        dp[0][0][0] = 1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int k=0;k<2;k++)
                    {
                        if(i+1 < n)
                        {
                            dp[i+1][j][0] += dp[i][j][k];
                            dp[i+1][j][0]%=MOD;
                        }
                        if(j+1 < m)
                        {
                            dp[i][j+1][1] += dp[i][j][k];
                            dp[i][j+1][1]%=MOD;
                        }
                    }
                }
                else
                {
                    if(i+1 < n)
                    {
                        dp[i+1][j][0] += dp[i][j][1];
                        dp[i+1][j][0]%=MOD;
                    }
                    if(j+1 < m)
                    {
                        dp[i][j+1][1] += dp[i][j][0];
                        dp[i][j+1][1]%=MOD;
                    }                  
                }
            }
        }

        res += dp[n-1][m-1][0];
        res += dp[n-1][m-1][1];
        res%=MOD;

        return res;
    }
};
