class Solution {
public:
    long long int dp[100001];
    vector <int> adj[100001];
    vector <int> C;
    int res = 0;
    void dfs(int now,int prev)
    {
        for(auto next : adj[now])
        {
            if(next==prev) continue;
            dfs(next,now);
            dp[now] = max(dp[now],dp[next]);
        }
        dp[now] += C[now];
        return;
    }
    void dfs2(int now,long long int U,int prev)
    {
       // cout << U << ' ' << now << ' ' << dp[0] << ' ' << dp[now] << '\n';
        if(U + dp[now] < dp[0])
        {
            res+=1;
            long long int M = 0;
            for(auto next : adj[now])
            {
                if(next==prev) continue;
                M = max(M,dp[next]);        
            }
            long long int X = dp[0] - U - M;
            for(auto next : adj[now])
            {
                if(next==prev) continue;
                dfs2(next,U+X,now);
            }
        }
        else
        {
            for(auto next : adj[now])
            {
                if(next==prev) continue;
                dfs2(next,U + C[now],now);
            }
        }
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        for(int i=0;i<n-1;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        C = cost;
        dfs(0,-1);
        dfs2(0,0,-1);
        return res;
    }
};
