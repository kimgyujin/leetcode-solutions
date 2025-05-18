class Solution {
public:
    int dy[4] = {-1,0,1,0};
    int dx[4] = {0,1,0,-1};
    vector <pair<int,int>> pos[26];
    int arr[26];
    int minMoves(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();
        vector <vector<int>> dist(n,vector<int>(m,1e9));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]>='A' && board[i][j]<='Z')
                {
                    pos[board[i][j]-'A'].push_back(make_pair(i,j));
                }
            }
        }
        
        for(int i=0;i<26;i++) arr[i] = 1e9;
        
        priority_queue <pair<int,pair<int,int>>> pque;
        dist[0][0] = 0;
        pque.push(make_pair(0,make_pair(0,0)));
        
        while(!pque.empty())
        {
            int y = pque.top().second.first;
            int x = pque.top().second.second;
            if(dist[y][x] < -pque.top().first)
            {
                pque.pop();
                continue;
            }
            pque.pop();
            
            if(y==n-1 && x==m-1) break;
            
            if(board[y][x]>='A' && board[y][x]<='Z')
            {
                if(arr[board[y][x]-'A'] > dist[y][x])
                {
                    arr[board[y][x]-'A'] = dist[y][x];
                    for(auto p : pos[board[y][x]-'A'])
                    {
                        int ny = p.first;
                        int nx = p.second;
                        if(dist[ny][nx] > dist[y][x])
                        {
                            dist[ny][nx] = dist[y][x];
                            pque.push(make_pair(-dist[ny][nx],make_pair(ny,nx)));
                        }
                    }
                }
            }
            
            for(int k=0;k<4;k++)
            {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
                if(board[ny][nx]=='#') continue;
                if(dist[ny][nx] > dist[y][x] + 1)
                {
                    dist[ny][nx] = dist[y][x] + 1;
                    pque.push(make_pair(-dist[ny][nx],make_pair(ny,nx)));
                }
            }
        }
        if(dist[n-1][m-1] >= 1e9)
        {
            dist[n-1][m-1] = -1;
        }
        
        return dist[n-1][m-1];
    }
};
