class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[2005][2005];
        memset(dp,false,sizeof(dp));
        int n = s.length();
        int m = p.length();
        
        dp[0][0] = true;
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
               if(dp[i][j]==false) continue;
                if(p[j]=='?') dp[i+1][j+1]=true;
                else if(p[j]=='*')
                {
                    dp[i][j+1] = true;
                    dp[i+1][j] = true;
                    dp[i+1][j+1]=true;
                }
                else if(s[i]==p[j])
                {
                    dp[i+1][j+1] = true;
                }
            }
        }
        
        return dp[n][m];
    }
};
