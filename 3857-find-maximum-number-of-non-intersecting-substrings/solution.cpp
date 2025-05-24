class Solution {
public:
    int dp[200005];
    vector <int> pos[26];
    int maxSubstrings(string s) {
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            int x = s[i] - 'a';
            pos[x].push_back(i);
        }
        
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        
        for(int i=0;i<n;i++)
        {
            dp[i+1] = max(dp[i+1],dp[i]);
            int x = s[i] - 'a';
            int idx = lower_bound(pos[x].begin(),pos[x].end(),i+3) - pos[x].begin();
            if(idx < pos[x].size())
            {
                int j = pos[x][idx] + 1;
                dp[j] = max(dp[j],dp[i] + 1);
            }
        }
        return dp[n];
    }
};
