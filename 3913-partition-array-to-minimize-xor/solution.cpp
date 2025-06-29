class Solution {
public:
    int dp[251][251];
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                dp[i][j] = 2e9;        
            }
        }

        dp[0][0] = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(dp[i][j] >= 2e9) continue;
                int val = 0;
                for(int a=i;a<n;a++)
                {
                    val^=nums[a];
                    dp[a+1][j+1] = min(dp[a+1][j+1],max(val,dp[i][j]));
                }
            }
        }

        return dp[n][k];
    }
};
