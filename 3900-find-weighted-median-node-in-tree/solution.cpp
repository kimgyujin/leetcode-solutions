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

    int func(int a,int d)
    {
        int res = a;
        for(int i=0;i<20;i++)
        {
            if(d&(1<<i))
            {
                res = parent[res][i]; 
            }
        }
        return res;
    }
    
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector <int> res;

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
            int a,b,lca;
            a = queries[i][0] + 1; 
            b = queries[i][1] + 1; 
            lca = getlca(a,b);
            if(b==lca)
            {
                int D = depth[a] - depth[b];
                int lo = 0;
                int hi = D;
                long long int weight = dist[a] - dist[b];
                while(lo<=hi)
                {
                    int mid = (lo + hi)/2;
                    int pos = func(a,mid);
                    long long int W = dist[a] - dist[pos];
                    if(2*W >= weight)
                    {
                        D = min(D,mid);
                        hi = mid - 1;
                    }
                    else
                    {
                        lo = mid + 1;
                    }
                }
                res.push_back(func(a,D) - 1);
            }
            else if(a==lca)
            {
                int D = depth[b] - depth[a];
                int lo = 0;
                int hi = D;
                D = 0;
                long long int weight = dist[b] - dist[a];
                while(lo<=hi)
                {
                    int mid = (lo + hi)/2;
                    int pos = func(b,mid);
                    long long int W = dist[pos] - dist[a];
                    if(2*W >= weight)
                    {
                        D = max(D,mid);
                        lo = mid + 1;
                    }
                    else
                    {
                        hi = mid - 1;
                    }
                }
                res.push_back(func(b,D) - 1);                
            }
            else
            {
                int D = depth[a] - depth[lca];
                int lo = 0;
                int hi = D;
                long long int addW = dist[b] - dist[lca];
                long long int weight = dist[b] + dist[a] - 2*dist[lca];
                D = 1e9;
                while(lo<=hi)
                {
                    int mid = (lo + hi)/2;
                    int pos = func(a,mid);
                    long long int W = dist[a] - dist[pos];
                    //cout << a << ' ' << b << ' ' << lca << ' ' << mid << ' ' << pos << ' ' << W << ' ' << weight << '\n';                    
                    if(2*W >= weight)
                    {
                        D = min(D,mid);
                        hi = mid - 1;
                    }
                    else
                    {
                        lo = mid + 1;
                    }
                }
                if(D!=1e9) 
                {
                    res.push_back(func(a,D) - 1);        
                }
                else
                {
                    int D = depth[b] - depth[lca];
                    int lo = 0;
                    int hi = D;
                    long long int addW = dist[a] - dist[lca];
                    long long int weight = dist[b] + dist[a] - 2*dist[lca];                    
                    D = 0;
                    while(lo<=hi)
                    {
                        int mid = (lo + hi)/2;
                        int pos = func(b,mid);
                        long long int W = dist[pos] - dist[lca] + addW;
                        //cout << a << ' ' << b << ' ' << lca << ' ' << mid << ' ' << pos << ' ' << W << ' ' << weight << '\n';
                        if(2*W >= weight)
                        {
                            D = max(D,mid);
                            lo = mid + 1;
                        }
                        else
                        {
                            hi = mid - 1;
                        }
                    }
                    res.push_back(func(b,D) - 1);    
                }
            }
        }        

        return res;
    }
};
