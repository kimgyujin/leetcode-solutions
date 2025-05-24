class Solution {
public:
    const long long int MOD = 1e9 + 7;
    int depth[100001];
    int parent[100001][20];
    vector <int> adj[100001];
    int max_level = (int)floor(log2(100001));

    void maketree(int now, int p)
    {
        depth[now] = depth[p]+1;
        parent[now][0]=p;

        for(int i=1;i<=max_level;i++)
        {
            int temp = parent[now][i-1];
            parent[now][i] = parent[temp][i-1];
        }

        for(auto next: adj[now])
        {
            if(p!=next)
            {
                maketree(next,now);
            }
        }
    }
    
    int getlca(int a,int b)
    {
        int tempa = a;
        int tempb = b;

        if(depth[a]!=depth[b])
        {
            if(depth[a] > depth[b])
            {
                int temp = a;
                a = b;
                b = temp;
            }

            for(int i=max_level;i>=0;i--)
            {
                if(depth[a]<=depth[parent[b][i]])
                {
                    b = parent[b][i];
                }
            }
        }

        int lca = a;

        if(a!=b)
        {
            for(int i=max_level;i>=0;i--)
            {
                if(parent[a][i]!=parent[b][i])
                {
                    a = parent[a][i];
                    b = parent[b][i];
                }
                lca = parent[a][i];
            }
        }        
        return lca;
    }
    
    int getdist(int a,int b,int lca)
    {
        return depth[a]+depth[b]-2*depth[lca];
    }
    
    long long int mypow(long long int x,long long int n)
    {
        long long int res = 1;
        while(n > 0)
        {
            if(n%2==1)
            {
                res*=x;
                res%=MOD;
            }
            x*=x;
            x%=MOD;
            n/=2;
        }
        return res;
    }
    
    
    int assignEdgeWeights(vector<vector<int>>& edges) 
    {
        int res;
        
        for(auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        maketree(1,0);
        
        int d = 0;
        int n = edges.size() + 1;
        for(int i=1;i<=n;i++) d = max(d,depth[i]);
        
        if(d==1) res = 0;
        else res = mypow(2,d-2);
        return res;
        
    }
};


