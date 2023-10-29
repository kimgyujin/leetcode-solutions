vector <pair<int,int>> adj[10000]; //edge
int parent[10000][15]; // parent[now][d] = now의 조상 중에, 거리가 2^d인 조상
/*
    6 -> 거리가 5인 조상을 찾고 싶음. 4 + 1
    6 -> parent[6][2] -> 2 -> parent[2][0] -> 1
    sparse table
    parent[now][0] 
*/
int depth[10000];
int memo[10000][15][26];
int cnt[26];
void dfs(int now)
{
	for(auto it: adj[now])
	{
        int next = it.first;
		if(depth[next]==-1)
		{
			parent[next][0]=now;
			depth[next] = depth[now]+1;
            memo[next][0][it.second] = 1; // 역간선 
			dfs(next);
		}
	}
}

int getlca(int x,int y,int size)
{
    if(depth[x] < depth[y]) // y -> 
    {
        int t = y;
        y = x;
        x = t;
    }

    int d = abs(depth[x]-depth[y]);

    for(int j=0; d>0 ;j++)
    {
        if(d%2)
        {
            x = parent[x][j];
        }
        d/=2;
    }

    /*
        lca
        depth[lca]

        (depth[u] - depth[lca])
    */
    if(x!=y) 
    {
        for(int j=size-1;j>=0;j--)
        {
            if(parent[x][j]!=-1 && parent[x][j] != parent[y][j]) //2^j
            {
                x = parent[x][j];
                y = parent[y][j];
            }
        }

        x = parent[x][0];
    }    

    return x;
}

class Solution 
{
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) 
    {
        for(int i=0;i<n;i++) adj[i].clear();
        vector <int> ans;

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2] - 1;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        memset(parent,0,sizeof(parent));
        memset(depth,-1,sizeof(depth));
        memset(memo,0,sizeof(memo));

        depth[0]=0;
        dfs(0);
        
        /*
            2^j
            u -> 2^0 
            u -> 2^1
            u -> 2^0 -> 2^0
        */
        int size = ceil(log2(n));
        
        for(int i=0;i<size-1;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(parent[j][i]!=-1)
                {
                    parent[j][i+1] = parent[parent[j][i]][i];
                    for(int k=0;k<26;k++)
                    {
                        memo[j][i+1][k] += memo[j][i][k];
                        memo[j][i+1][k] += memo[parent[j][i]][i][k];
                    }
                }
            }
        }
        
        for(auto it : queries)
        {
            int u = it[0];
            int v = it[1];
            int lca = getlca(u,v,size);

            //cout << u << ' ' << v << ' ' << lca << '\n';
            memset(cnt,0,sizeof(cnt));
            int total = depth[u] + depth[v] - 2*depth[lca];
            int Max = 0;
          
            int d = depth[u] - depth[lca];

            for(int j=0;d>0;j++)
            {
                if(d%2==1)
                {
                    for(int k=0;k<26;k++)
                    {
                        cnt[k] += memo[u][j][k];
                        Max = max(Max,cnt[k]);
                    }
                    u = parent[u][j];
                }
                d/=2;
            }

            d = depth[v] - depth[lca];
            for(int j=0;d>0;j++)
            {
                if(d%2==1)
                {
                    for(int k=0;k<26;k++)
                    {
                        cnt[k] += memo[v][j][k];
                        Max = max(Max,cnt[k]);

                    }
                    v = parent[v][j];
                }
                d/=2;
            }            
  
            ans.push_back(total - Max);
        }
        
        return ans;
    }
};
