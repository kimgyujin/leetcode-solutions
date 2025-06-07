class Solution {
public:
    const long long int MOD = 1e9 + 7;
    long long int dp[501][1<<10];
    vector <int> adj[501];
    vector <int> v;
    long long int res = 0;
    long long int dp2[1<<10];
    void solve(int now)
    {
        int mask = 0;
        int tmp = v[now];
        bool ok = true;
        dp[now][0] = 0;
        while(tmp > 0)
        {
            int b = tmp%10;
            tmp/=10;
            if((mask&(1<<b)))
            {
                ok = false;
                break;
            }
            mask |= (1<<b);
        }
        if(ok)
        {
            dp[now][mask] = v[now];
        }

        for(auto next : adj[now])
        {
            solve(next);  
            memcpy(dp2,dp[now],sizeof(dp[now]));
            memset(dp[now],-1,sizeof(dp[now]));
            for(int a=0;a<(1<<10);a++)
            {
                if(dp2[a]==-1) continue;
                dp[now][a] = max(dp[now][a],dp2[a]);
                for(int b=0;b<(1<<10);b++)
                {
                    if(dp[next][b]==-1) continue;
                    if((a&b)==0)
                    {
                        dp[now][a|b] = max(dp[now][a|b],dp2[a] + dp[next][b]);
                    }
                }
            }
        }

        long long int Max = 0;
        for(int i=0;i<(1<<10);i++)
        {
            Max = max(Max,dp[now][i]);
        }
        res += Max;
        res%=MOD;
        return;
    }
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        memset(dp,-1,sizeof(dp));
        int n = vals.size();
        v = vals;
        for(int i=0;i<n;i++)
        {
            if(par[i]!=-1) adj[par[i]].push_back(i);        
        }
        solve(0);
        return res;
    }
};
