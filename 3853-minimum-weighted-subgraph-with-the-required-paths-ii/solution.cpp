class Solution {
public:
    int depth[100001];
    int parent[100001][20];
    vector <pair<int,int>> adj[100001];
    long long int dist[100001];
    int max_level = (int)floor(log2(100001));

    void maketree(int now, int p, int val)
    {
        depth[now] = depth[p]+1;
        if(now!=1)
        {
            dist[now] = dist[p]+val;
        }
        parent[now][0]=p;

        for(int i=1;i<=max_level;i++)
        {
            int temp = parent[now][i-1];
            parent[now][i] = parent[temp][i-1];
        }

        for(auto it: adj[now])
        {
            int next = it.first;
            int length = it.second;
            if(p!=next)
            {
                maketree(next,now,length);
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
        return dist[a]+dist[b]-2*dist[lca];
    }
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries)     
    {
        vector <int> res;
        int n = edges.size() + 1;

        for(int i=0;i<n-1;i++)
        {
            int a,b,c;
            a = edges[i][0] + 1;
            b = edges[i][1] + 1;
            c = edges[i][2];
            adj[a].push_back(make_pair(b,c));
            adj[b].push_back(make_pair(a,c));
        }

        depth[0]=-1;
        maketree(1,0,0);

        int m = queries.size();
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            a = queries[i][0] + 1; //src1
            b = queries[i][1] + 1; //src2
            c = queries[i][2] + 1; //dest
            //cout << a << ' ' << b << ' ' << c << '\n';
            int lca1 = getlca(a,b);
            int lca2 = getlca(a,c);
            int lca3 = getlca(b,c);
            int D = dist[a] + dist[b] + dist[c] - dist[lca1] - dist[lca2] - dist[lca3];
            res.push_back(D);
        }

        return res;
    }    
};
