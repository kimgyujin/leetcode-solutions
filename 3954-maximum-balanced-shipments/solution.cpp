class Solution {
public:
    int dp[100005];
    int maxBalancedShipments(vector<int>& weight) {
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        int n = weight.size();
        for(int i=0;i<n;i++)
        {
            if(dp[i]==-1) continue;
            dp[i+1] = max(dp[i+1],dp[i]);
            if(i+2 <= n)
            {
                if(weight[i+1] < weight[i])
                {
                    dp[i+2] = max(dp[i+2],dp[i] + 1);
                }
            }
        }
        return dp[n];
    }
};
