class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector <vector<int>> adj(n*n + 1);
        bool f = true;
        vector <int> move(n*n+1);
        for(int i=1;i<=n*n;i++) move[i] = i;
        
        for(int i=n-1;i>=0;i--)
        {
            if(f)
            {
                for(int j=0;j<n;j++)
                {
                    if(board[i][j]==-1) continue;
                    int u = (n-1-i)*n + j + 1;
                    move[u] = board[i][j];
                }
                f = false;
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    if(board[i][j]==-1) continue;
                    int u = (n-1-i)*n + (n-1-j) + 1;
                    move[u] = board[i][j];
                }
                f = true;                
            }
        }
        
        vector <int> dist(n*n+1,-1);
        queue <int> que;
        
        dist[move[1]] = 0;
        que.push(move[1]);
        
        while(!que.empty())
        {
            int now = que.front();
            que.pop();
            
            for(int i=1;i<=6;i++)
            {
                int next = now + i;
                if(next > n*n) break;
                next = move[next];
                if(dist[next] == -1)
                {
                    dist[next] = dist[now] + 1;
                    que.push(next);
                }
            }
            for(auto next : adj[now])
            {
                next = move[next];
                if(dist[next] == -1)
                {
                    dist[next] = dist[now] + 1;
                    que.push(next);
                }              
            }
        }
        return dist[n*n];
    }
};
