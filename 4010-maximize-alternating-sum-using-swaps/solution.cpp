class Solution {
public:
    int uf[100001];
    vector <int> v[100001];
    int cnt[100001][2];
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
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        memset(uf,-1,sizeof(uf));
        long long int res = -1e18;
        long long int sum = 0;
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(i%2==0) 
            {
                sum += nums[i];
            }
            else 
            {
                sum -= nums[i];
            }
        }
        res = max(res,sum);
        for(auto q : swaps)
        {
            merge(q[0],q[1]);
        }

        for(int i=0;i<n;i++)
        {
            int x = find(i);
            v[x].push_back(nums[i]);
            cnt[x][i%2] += 1;
        }

        sum = 0;

        for(int i=0;i<n;i++)
        {
            if(uf[i] < 0)
            {
                sort(v[i].begin(),v[i].end());
                for(int j=0;j<v[i].size();j++)
                {
                    if(j < cnt[i][1]) sum -= v[i][j];
                    else sum += v[i][j];
                }
            }
        }

        res = max(res,sum);
        
        return res;
    }
};
