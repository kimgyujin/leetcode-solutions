class Solution {
public:
    const long long int MOD = 1e9 + 7;
    long long int dp[100005][3][3];
    
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        memset(dp,0,sizeof(dp));
        dp[0][2][2] = 1;

        for(int i=0;i<n;i++)
        {
            int p = nums[i]%2;
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    dp[i+1][j][k] += dp[i][j][k];
                    dp[i+1][j][k]%=MOD;
                    if(j==k && j==p && k==p) continue;
                    dp[i+1][k][p] += dp[i][j][k];
                    dp[i+1][k][p]%=MOD;
                }
            }
        }

        long long int res = 0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i==2 && j==2) continue;
                res += dp[n][i][j];
                res%=MOD;
            }
        }

        return res;
    }
};
