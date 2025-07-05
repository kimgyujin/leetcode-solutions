class Solution {
public:
    vector <pair<int,pair<int,int>>> adj[100005];
    int minTime(int n, vector<vector<int>>& edges) {
       vector <int> dist(n,1e9); 
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int l = e[2];
            int r = e[3];
            // directed
            adj[u].push_back(make_pair(v,make_pair(l,r)));
        }

        dist[0] = 0;
        priority_queue <pair<int,int>> pque;
        pque.push(make_pair(-dist[0],0));

        while(!pque.empty())
        {
            int now = pque.top().second;
            if(dist[now] < -pque.top().first)
            {
                pque.pop();
                continue;
            }
            pque.pop();

            if(now==n-1)
            {
                return dist[now];
            }

            for(auto e : adj[now])
            {
                int next = e.first;
                if(dist[now] < e.second.first)
                {
                    if(dist[next] > e.second.first+1)
                    {
                        dist[next] = e.second.first+1;
                        pque.push(make_pair(-dist[next],next));
                    }
                }
                else if(dist[now] >= e.second.first && dist[now] <= e.second.second)
                {
                    if(dist[next] > dist[now]+1)
                    {
                        dist[next] = dist[now]+1;
                        pque.push(make_pair(-dist[next],next));
                    }
                }                
            }
        }

        return -1;
    }
};
