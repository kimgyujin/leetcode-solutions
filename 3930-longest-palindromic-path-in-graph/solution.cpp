class Solution {
public:
    int dp[1<<14][14][14];
    bool edge[14][14];
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        memset(edge,false,sizeof(edge));
        memset(dp,-1,sizeof(dp));
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            edge[u][v] = true;
            edge[v][u] = true;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(label[i]==label[j])
                {
                    if(i==j) dp[(1<<i)][i][j] = 1;
                    else
                    {
                        if(edge[i][j]) dp[(1<<i) + (1<<j)][i][j] = 2; 
                    }
                }
            }
        }

        int res = 0;
        for(int i=0;i<(1<<n);i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(dp[i][j][k]==-1) continue;
                    res = max(res,dp[i][j][k]);
                    for(int a=0;a<n;a++)
                    {
                        if((i&(1<<a))) continue;
                        if(edge[j][a]==false) continue;
                        for(int b=0;b<n;b++)
                        {
                            if((i&(1<<b))) continue;
                            if(a==b) continue;
                            if(edge[k][b]==false) continue;
                            if(label[a]==label[b])
                            {
                                int ni = i + (1<<a) + (1<<b);
                                dp[ni][a][b] = max(dp[ni][a][b],dp[i][j][k] + 2);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
