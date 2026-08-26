int dp[100001];
int ans[100001];
vector <int> adj[100001];
vector <int> a;
int dfs(int now,int prev)
{
    if(dp[now]!=-1e9) return dp[now];
    dp[now] = 0;
    if(a[now]==0) dp[now]-=1;
    else dp[now]+=1;
    for(auto next : adj[now])
    {
        if(next==prev) continue;
        dfs(next,now);
        //cout << now << ' ' << dp[now] << ' ' << dp[next] << ' ' << next << ' ' << prev << '\n';
        dp[now] += max(0,dp[next]);
    }
    return dp[now];
}
void solve(int now,int prev,int U)
{
    ans[now] = dp[now] + U;
    for(auto next : adj[now])
    {
        if(next==prev) continue;
        int tmp = dp[now] - max(0,dp[next]);
        solve(next,now,max(0,U+tmp));
    }
}

class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) 
    {
        for(int i=0;i<n;i++)
        {
            dp[i] = -1e9;
            adj[i].clear();
            ans[i] = 0;
        }
        a.clear();
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        a = good;
        dfs(0,-1);
        solve(0,-1,0);
        for(int i=0;i<n;i++) cout << i << ' ' << dp[i] << '\n';
        vector <int> res;
        for(int i=0;i<n;i++)
        {
            res.push_back(ans[i]);
        }
        return res;
    }
};
