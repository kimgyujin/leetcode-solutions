class Solution {
public:
    int uf[50005];
    int find(int x)
    {
        if(uf[x] < 0) return x;
        return uf[x] = find(uf[x]);
    }
    void merge(int x,int y)
    {
        x = find(x);
        y = find(y);
        if(x==y) return;
        uf[x] += uf[y];
        uf[y] = x;
        return;

    }
    int minCost(int n, vector<vector<int>>& edges, int k) {

        int lo = 0;
        int hi = 1e6;
        int res = 1e6;
        while(lo<=hi)
        {
            int mid = (lo + hi)/2;
            memset(uf,-1,sizeof(uf));
            for(auto e : edges)
            {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if(w <= mid) merge(u,v);
            }
            int cnt = 0;
            for(int i=0;i<n;i++)
            {
                if(uf[i] < 0) cnt+=1;        
            }
            if(cnt <= k)
            {
                res = min(res,mid);
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return res;

        
    }
};
