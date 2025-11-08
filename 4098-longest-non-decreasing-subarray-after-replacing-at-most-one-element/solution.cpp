class Solution {
public:
    int dp[100005][2];
    int longestSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<=2)
        {
            return n;
        }
        
        memset(dp,-1,sizeof(dp));
        int res = 0;
        dp[1][0] = 1;
        for(int i=1;i<n;i++)
        {
            dp[i+1][0] = 1;
            if(nums[i-1] <= nums[i])
            {
                dp[i+1][0] = max(dp[i+1][0],dp[i][0] + 1);
                if(dp[i][1]!=-1)
                {
                    dp[i+1][1] = max(dp[i+1][1],dp[i][1] + 1);
                }
            }
            if(i>=2)
            {
                if(nums[i-2] <= nums[i]) dp[i+1][1] = max(dp[i+1][1],dp[i-1][0] + 2);
            }
        }

        for(int i=0;i<=n;i++)
        {
            //cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
            res = max(res,max(dp[i][0],dp[i][1]));
            if(dp[i][0] < n) res = max(res,dp[i][0] + 1);
        }
        return res;
    }
};
