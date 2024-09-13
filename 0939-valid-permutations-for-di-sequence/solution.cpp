class Solution 
{
    const long long int MOD = 1e9 + 7;
    long long int dp[205][205];
    long long int psum[205];
    public:
        int numPermsDISequence(string s) 
        {
            dp[1][1] = 1;
            psum[1] = 1;
            int n = s.length() + 1;
            for (int i = 2; i <= n; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    if (s[i-2] == 'I')
                    {
                        dp[i][j] += psum[j - 1] % MOD;
                        dp[i][j] %= MOD;
                    }
                    else
                    {
                        long long int val = psum[i - 1] - psum[j - 1];
                        val %= MOD;
                        if (val < 0) val += MOD;
                        dp[i][j] += val;
                        dp[i][j] %= MOD;
                    }
                }
                for (int j = 1; j <= i; j++)
                {
                    psum[j] = psum[j - 1] + dp[i][j];
                    psum[j] %= MOD;
                }
            }

            long long int res = 0;

            for (int i = 0; i <= n; i++)
            {
                res += dp[n][i];
                res %= MOD;
            }

            return res;
        }
};
