class Solution {
public:
    int uf[100001];
    int backup[100001];
    int find(int x)
    {
        if(uf[x] < 0) return x;
        return uf[x] = find(uf[x]);
    }
    bool merge(int x,int y)
    {
        x = find(x);
        y = find(y);
        if(x==y) return false;
        uf[x] += uf[y];
        uf[y] = x;
        return true;
    }
    
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        memset(uf,-1,sizeof(uf));
        int Min = 1e9;
        int res = -1;
        vector <int> v;   
        int Cnt = 0;

        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int s = e[2];
            if(e[3]==1)
            {
                Min = min(Min,s);
                if(merge(u,v)==false)
                {
                    return -1;
                }
                Cnt+=1;
            }
        }

        vector <pair<int,pair<int,int>>> E;
        for(auto e : edges)
        {
            if(e[3]==0)
            {
                E.push_back(make_pair(e[2],make_pair(e[0],e[1])));
            }
        }

        sort(E.rbegin(),E.rend());
        int lo = -1;
        int hi = Min;
        memcpy(backup,uf,sizeof(uf));
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            bool ok = true;
            memcpy(uf,backup,sizeof(backup));
            int K = k;
            int cnt = 0;
            for(auto e : E)
            {
                int u = e.second.first;
                int v = e.second.second;
                if(merge(u,v))
                {
                    if(e.first < mid)
                    {
                        if(2*e.first < mid)
                        {
                            ok = false;
                            break;
                        }
                        else
                        {
                            if(K==0)
                            {
                                ok = false;
                                break;
                            }
                            K-=1;
                            cnt+=1;
                        }
                    }
                    else
                    {
                        cnt+=1;
                    }
                }
            }
            if(Cnt + cnt < n - 1)
            {
                ok = false;
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
