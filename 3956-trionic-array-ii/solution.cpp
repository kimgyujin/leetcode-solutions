class Solution {
public:
    long long int dp[100005][3];
    long long maxSumTrionic(vector<int>& nums) {
        long long int res = -1e18;
        int n = nums.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            {
                dp[i][j] = -1e18;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(i > 0)
            {
                long long int x = nums[i] + nums[i-1];
                if(nums[i] > nums[i-1])
                {
                    dp[i+1][0] = max(dp[i+1][0],x);
                    dp[i+1][0] = max(dp[i+1][0],dp[i][0] + nums[i]);
                    dp[i+1][2] = max(dp[i+1][2],dp[i][1] + nums[i]);
                    dp[i+1][2] = max(dp[i+1][2],dp[i][2] + nums[i]);

                }
                else if(nums[i] < nums[i-1])
                {
                    dp[i+1][1] = max(dp[i+1][1],dp[i][0] + nums[i]);
                    dp[i+1][1] = max(dp[i+1][1],dp[i][1] + nums[i]);                    
                }
            }
            res = max(res,dp[i+1][2]);
        }

        return res;
    }
};
