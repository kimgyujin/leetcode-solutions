long long int dp[20][21][10][3][2];
long long int solve(long long int x)
{
    string s = "";
    long long int tmp = x;
    while(tmp > 0)
    {
        s = (char)(tmp%10 + '0') + s;
        tmp/=10;
    }
    int n = s.length();
    memset(dp,0,sizeof(dp));
    int a = s[0] - '0';
    for(int i=1;i<=a;i++)
    {
        dp[1][0][i][1][i==a] += 1;
    }

    for(int i=1;i<n;i++)
    {
        int a = s[i] - '0';
        for(int j=0;j<i;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int l=0;l<3;l++)
                {
                    if(dp[i][j][k][l][0]!=0)
                    {
                        for(int b=0;b<10;b++)
                        {
                            int f = 0;
                            if(b < k) f = 0;
                            else if(b==k) f = 1;
                            else f = 2;
                            if((f==0 && l==2) || (f==2 && l==0))
                            {
                                dp[i+1][j+1][b][f][0] += dp[i][j][k][l][0];
                            }
                            else
                            {
                                dp[i+1][j][b][f][0] += dp[i][j][k][l][0];
                            }
                        }
                    }
                    if(dp[i][j][k][l][1]!=0)
                    {
                        for(int b=0;b<=a;b++)
                        {
                            int f = 0;
                            if(b < k) f = 0;
                            else if(b==k) f = 1;
                            else f = 2;
                            if((f==0 && l==2) || (f==2 && l==0))
                            {
                                dp[i+1][j+1][b][f][b==a] += dp[i][j][k][l][1];
                            }
                            else
                            {
                                dp[i+1][j][b][f][b==a] += dp[i][j][k][l][1];
                            }
                        }
                    }                    
                }
            }
        }

        for(int j=1;j<10;j++)
        {
            dp[i+1][0][j][1][0] += 1;
        }
    }

    long long int res = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<3;k++)
            {
                for(int l=0;l<2;l++)
                {
                    res += (dp[n][i][j][k][l]*i);
                }
            }
        }
    }

    return res;
}
class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        long long int res = solve(num2);
        res -= solve(num1-1);
        return res;
    }
};
