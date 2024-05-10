const long long int MOD = 1e9 + 7;
long long int dp[41][1<<10];
bool chk[41][10];

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        memset(dp,0,sizeof(dp));
        memset(chk,false,sizeof(chk));

        for(int i=0;i<n;i++)
        {
            for(auto j : hats[i])
            {
                chk[j-1][i] = true;
            }
        }

        dp[0][0] = 1;

        for(int i=0;i<40;i++)
        {
            for(int j=0;j<(1<<n);j++)
            {
                if(dp[i][j]==0) continue;
                dp[i+1][j] += dp[i][j];
                dp[i+1][j]%=MOD;
                for(int k=0;k<n;k++)
                {
                    if((j&(1<<k))) continue;
                    if(chk[i][k])
                    {
                        dp[i+1][j + (1<<k)] += dp[i][j];
                        dp[i+1][j + (1<<k)]%=MOD;
                    }
                }
            }
        }

        return dp[40][(1<<n)-1];
    }
};
