int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n,m;
int dist[20][20][1<<10][51];
int arr[20][20];
int sy,sx;
int num;
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        n = classroom.size();
        m = classroom[0].size();

        memset(arr,-1,sizeof(arr));

        num = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(classroom[i][j]=='L')
                {
                    arr[i][j] = num++;
                }
                else if(classroom[i][j]=='S')
                {
                    sy = i;
                    sx = j;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<(1<<num);k++)
                {
                    for(int l=0;l<=energy;l++)
                    {
                        dist[i][j][k][l] = -1;
                    }
                }
            }
        }
        dist[sy][sx][0][energy] = 0;
        queue <pair<pair<int,int>,pair<int,int>>> que;
        que.push(make_pair(make_pair(sy,sx),make_pair(0,energy)));
        while(!que.empty())
        {
            int y = que.front().first.first;
            int x = que.front().first.second;
            int mask = que.front().second.first;
            int e = que.front().second.second;
            que.pop();

            if(mask==(1<<num)-1)
            {
                return dist[y][x][mask][e];
            }
            if(e > 0)
            {
                for(int k=0;k<4;k++)
                {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    int nmask = mask;
                    int ne = e - 1;
                    if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
                    if(classroom[ny][nx]=='X') continue;
                    if(classroom[ny][nx]=='L') nmask |= (1<<arr[ny][nx]);
                    if(classroom[ny][nx]=='R') ne = energy;
                    if(dist[ny][nx][nmask][ne]==-1)
                    {
                        dist[ny][nx][nmask][ne] = dist[y][x][mask][e] + 1;
                        que.push(make_pair(make_pair(ny,nx),make_pair(nmask,ne)));
                    }
                }
            }
        }

        return -1;
    }
};
