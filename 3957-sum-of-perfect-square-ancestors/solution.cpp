class Solution {
public:
    map<vector<int>,int> cnt;
    vector <int> adj[100000];
    vector <int> num;
    int arr[100001];
    long long int res = 0;
    void dfs(int now,int prev)
    {
        map <int,int> count;
        int val = num[now];
        while(val > 1)
        {
            int x = arr[val];
            count[x] += 1;
            val/=x;
        }
        vector <int> tmp;
        for(auto it : count)
        {
            if(it.second%2==1) tmp.push_back(it.first);
        }

        if(cnt.find(tmp)!=cnt.end()) res += cnt[tmp];
        cnt[tmp]+=1;
        for(auto next : adj[now])
        {
            if(next==prev) continue;
            dfs(next,now);
        }
        cnt[tmp]-=1;
    }
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) 
    {
        for(auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        num = nums;
        memset(arr,-1,sizeof(arr));
        arr[1] = 1;
        for(int i=2;i<=100000;i++)
        {
            if(arr[i]==-1)
            {
                for(int j=i;j<=100000;j+=i)
                {
                    arr[j] = i;
                }
            }
        }

        dfs(0,-1);

        return res;
    }
};
