class Solution {
    vector <vector<int>> adj;
    vector <vector<long long int>> dp1,dp2;
    vector <int> costs;
    vector <long long int> res;

    void dfs(int now,int prev)
    {
        for(auto next : adj[now])
        {
            if(next==prev) continue;
            dfs(next,now);
            for(auto it : dp1[next])
            {
                dp1[now].push_back(it);
            }
            for(auto it : dp2[next])
            {
                dp2[now].push_back(it);
            }            
        }
        if(costs[now] > 0) dp1[now].push_back(costs[now]);
        else dp2[now].push_back(costs[now]);
        sort(dp1[now].rbegin(),dp1[now].rend());
        sort(dp2[now].begin(),dp2[now].end());
        if(dp1[now].size() + dp2[now].size() < 3)
        {
            res[now] = 1;
        }
        else
        {
            long long int val = 0;
            if(dp1[now].size() >= 3)
            {
                val = max(val,dp1[now][0] * dp1[now][1] * dp1[now][2]);
            }
            if(dp1[now].size() >= 1 && dp2[now].size() >= 2)
            {
                val = max(val,dp1[now][0]*dp2[now][0]*dp2[now][1]);
            }
            res[now] = val;
        }

        if(dp1[now].size() > 3)
        {
            vector <long long int> tmp;
            for(int i=0;i<3;i++) tmp.push_back(dp1[now][i]);
            dp1[now] = tmp;
        }
        if(dp2[now].size() > 2)
        {
            vector <long long int> tmp;
            for(int i=0;i<2;i++) tmp.push_back(dp2[now][i]);
            dp2[now] = tmp;
        }
        return;
    }
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = edges.size() + 1;
        adj.resize(n);
        dp1.resize(n);
        dp2.resize(n);
        res.resize(n);
        costs = cost;
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1);
        return res;
    }
};
