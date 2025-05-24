class Solution {
public:
    long long int dp[11][82][82][2];
    long long int solve(string s,int x,int flag)
    {
        memset(dp,0,sizeof(dp));
        int n = s.length();
        
        int y = s[0] - '0';
        for(int i=1;i<=y;i++)
        {
            int f = 0;
            if(i==y) f = 1;
            if(i<=x) dp[1][i][i%x][f] += 1;
        }

        for(int i=1;i<n;i++)
        {
            int y = s[i] - '0';
            for(int j=0;j<=x;j++)
            {
                for(int k=0;k<x;k++)
                {
                    if(dp[i][j][k][0]!=0)
                    {
                        for(int a=0;a<10;a++)
                        {
                            if(j+a<=x) dp[i+1][j+a][(k*a)%x][0] += dp[i][j][k][0];
                        }
                    }
                    if(dp[i][j][k][1]!=0)
                    {
                        for(int a=0;a<=y;a++)
                        {
                            int f = 0;
                            if(a==y) f = 1;
                            if(j+a<=x) dp[i+1][j+a][(k*a)%x][f] += dp[i][j][k][1];
                        }
                    }
                }
            }

            for(int j=1;j<10;j++)
            {
                if(j<=x) dp[i+1][j][j%x][0] += 1;
            }
        }

        int res = dp[n][x][0][0];
        if(flag) res += dp[n][x][0][1];
        return res;
    }
    int beautifulNumbers(int l, int r) {
        int res = 0;
        stringstream ss1,ss2;
        ss1 << l;
        ss2 << r;
        string L = ss1.str();
        string R = ss2.str();
        for(int s=1;s<=81;s++)
        {
            int val = solve(R,s,true);
            val -= solve(L,s,false);
            res += val;
        }
        return res;
    }
};
