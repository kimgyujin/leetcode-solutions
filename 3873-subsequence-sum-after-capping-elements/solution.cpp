class Solution {
public:
    bool dp[4001][4001];
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        int M = 0;
        
        sort(nums.begin(),nums.end());
        memset(dp,false,sizeof(dp));
        dp[0][0] = true;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(dp[i][j]==false) continue;
                dp[i+1][j] = true;
                if(j + nums[i] <= k)
                {
                    dp[i+1][j+nums[i]] = true;
                }
            }
        }

        vector <bool> res(n,false);
        int idx = n;
        for(int i=n;i>=1;i--)
        {
            while(idx > 0)
            {
                if(nums[idx-1] < i) break;
                idx-=1;
            }

            bool ok = false;
            for(int j=0;j<=k;j++)
            {
                if(dp[idx][j])
                {
                    int X = k - j;
                    if(X%i==0 && j + (n-idx)*i >= k)
                    {
                        ok = true;
                        break;
                    }
                }
            }
            res[i-1] = ok;
        }
        
        return res;
    }
};
