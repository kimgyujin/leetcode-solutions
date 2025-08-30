class Solution {
public:
    set <int> S[2];
    int visited[100001];
    int minOperations(string s, int k) {
        memset(visited,0,sizeof(visited));

        int cnt = 0;
        int n = s.length();

        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') cnt+=1;
        }

        memset(visited,-1,sizeof(visited));
        visited[cnt] = 0;
        for(int i=0;i<=n;i++) S[i%2].insert(i);

        queue <int> que;
        S[cnt%2].erase(cnt);
        que.push(cnt);

        while(!que.empty())
        {
            int now = que.front();
            que.pop();

            if(now==n) break;

            int nf = (now%2);
            if(k%2==1) nf = 1 - nf;

            int cnt0 = n - now;
            int cnt1 = now;

            int val = k - now;
            int a = min(cnt0,k);
            int R = now + a - (k-a);
            auto it = S[nf].lower_bound(val);

            while(1)
            {
                if(it==S[nf].end()) break;
                auto next = *it;
                if(next > R) break;
                visited[next] = visited[now] + 1;
                que.push(next);
                it++;
                S[nf].erase(next);
            }
            
        }
        return visited[n];
    }
};
