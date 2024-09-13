class Solution {
    const long long int MOD = 1e9 + 7;
    long long int dp[24][401][2];
    long long int solve(string s,int f,int l,int r)
    {
        int n = s.length();
        memset(dp,0,sizeof(dp));
        long long int res = 0;

        int x = s[0] - '0';
        for(int i=1;i<=x;i++)
        {
            dp[1][i][i==x] += 1;
        }

        for(int i=1;i<n;i++)
        {
            int x = s[i] - '0';
            for(int j=0;j<=r;j++)
            {
                if(dp[i][j][0]!=0)
                {
                    for(int a=0;a<10;a++)
                    {
                        if(j+a > r) break;
                        dp[i+1][j+a][0] += dp[i][j][0];
                        dp[i+1][j+a][0]%=MOD;
                    }
                }
                if(dp[i][j][1]!=0)
                {
                    for(int a=0;a<=x;a++)
                    {
                        if(j+a > r) break;
                        dp[i+1][j+a][a==x] += dp[i][j][1];
                        dp[i+1][j+a][a==x]%=MOD;
                    }
                }                
            }

            for(int j=1;j<10;j++)
            {
                dp[i+1][j][0] += 1;
                dp[i+1][j][0]%=MOD;
            }
        }

        for(int i=l;i<=r;i++)
        {
            res += dp[n][i][0];
            res%=MOD;
            if(f==1)
            {
                res += dp[n][i][1];
                res%=MOD;
            }
        }
        return res;
    }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        long long int res = solve(num2,1,min_sum,max_sum);
        res -= solve(num1,0,min_sum,max_sum);
        res+=MOD;
        res%=MOD;
        return res;
    }
};
