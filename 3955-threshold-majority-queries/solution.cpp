int sq;
    
class Solution {
public:
    struct Query {
        int idx, l, r, threshold;
        int V;
        int ans;
        Query(int ii, int ll, int rr, int tt) :idx(ii), l(ll), r(rr), threshold(tt), V(l / sq) {}
    };
    
    int N, M;
    unordered_map <int,int> cnt;
    int table[10001];
    int res;
    set <int> S[10001];
    
    void Remove(int data) 
    {
        int x = cnt[data];
        if(x > 0)
        {
            //cout << data << ' ' << cnt[data] << ' ';
            table[x]--;
            if (x == res && !table[x])
            {
                res--;
            }
            if(S[x].find(data)!=S[x].end()) S[x].erase(data);
            x-=1;
            cnt[data] = x;
            if(x > 0) 
            {
                S[x].insert(data);
                table[x]++;
            }
        }
    }
    
    void Insert(int data) 
    {
        int x = cnt[data];
        if (x != 0)
        {
            table[x]--;
        }
        if(S[x].find(data)!=S[x].end()) S[x].erase(data);
        cnt[data] = x + 1;
        x+=1;
        table[x]++;
        S[x].insert(data);
        if(res < x)
        {
            res = x;
        }
    }
        
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        vector <int> ret;
        vector<Query> save;
        N = nums.size();
        M = queries.size();
        sq = (int)sqrt(N);
        for (int m = 0; m < M; m++) 
        {
            int u, v, t;
            u = queries[m][0];
            v = queries[m][1];
            t = queries[m][2];
            if (u > v)
            {
                swap(u, v);
            }
            save.emplace_back(Query(m, u, v, t));
    
        }
    
        sort(save.begin(), save.end(), [&](Query const& a, Query const& b)->bool {
            if (a.V == b.V) return a.r < b.r;
            return a.V < b.V;
            });
    
    
        int L = save[0].l, R = save[0].l - 1;
    
        for (int m = 0; m < M; m++) {
            while (L > save[m].l) 
            {
                L--;
                Insert(nums[L]);
            }
    
            while (R < save[m].r) 
            {
                R++;
                Insert(nums[R]);
            }

            while (L < save[m].l) 
            {
                Remove(nums[L]);
                L++;
            }
            
            while (R > save[m].r) 
            {
                Remove(nums[R]);
                R--;
            }
            if(res < save[m].threshold) save[m].ans = -1;
            else
            {
                auto it = S[res].begin();
                save[m].ans = *it;
            }
        }
    
        sort(save.begin(), save.end(), [&](Query const& a, Query const& b)->bool 
        {
            return a.idx < b.idx;
        });
    
        for (int m = 0; m < M; m++)
        {
            ret.push_back(save[m].ans);
        }        
        return ret;
    }
};
