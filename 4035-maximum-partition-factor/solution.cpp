class Solution {
public:
    vector <int> adj[500];
    int color[500];
    bool ok = true;
    void dfs(int now)
    {
        for(auto next : adj[now])
        {
            if(color[next]==-1)
            {
                color[next] = 1 - color[now];
                dfs(next);
            }
            else
            {
                if(color[next]==color[now])
                {
                    ok = false;
                }
            }
        }
    }
    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if(n==2)
        {
            return 0;
        }
        int res = 0;
        int lo = 0;
        int hi = 1e9;

        while(lo<=hi)
        {
            for(int i=0;i<n;i++)
            {
                adj[i].clear();
                color[i] = -1;
            }
            
            int mid = (lo + hi)/2;

            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    if(dist < mid)
                    {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }

            ok = true;
            for(int i=0;i<n;i++)
            {
                if(color[i]==-1)
                {
                    color[i] = 0;
                    dfs(i);
                }
            }
                
            if(ok)
            {
                res = max(res,mid);
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return res;
    }
};
