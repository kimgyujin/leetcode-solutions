class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        const long long int MOD = 1e9 + 7;
        vector <long long int> dp(r+1,0);
        vector <int> cnt(20001,0);
        for(auto num : nums) cnt[num] += 1;
        
        dp[0] = cnt[0] + 1;
        for(int i=1;i<=20000;i++)
        {
            if(cnt[i]==0) continue;
            for(int j=r;j>=0;j--)
            {
                if(dp[j]==0) continue;
                for(int k=1;k<=cnt[i];k++)
                {
                    if(j + k*i > r) break;
                    dp[j + k*i] += dp[j];
                    dp[j + k*i]%=MOD;
                }
            }
        }
        
        long long int res = 0;
        for(int i=l;i<=r;i++)
        {
            res += dp[i];
            res%=MOD;
        }
        
        return res;
    }
};
