class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); 

    int val = 2e9;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j] >= 1e9) continue;
            int dy = (n/2);
            int dx = (n/2);
    
            int y[4];
            int x[4];
            y[0] = i;
            x[0] = j;
            if(n%2)
            {
            for(int k=1;k<4;k++)
            {
                int Y = y[k-1] - dy;
                int X = x[k-1] - dx;
                int ny = X;
                int nx = -Y;
                ny += dy;
                nx += dx;
                y[k] = ny;
                x[k] = nx;
            }
            }
            else
            {
                dy = 2*n - 1;
                dx = 2*n - 1;
                dy/=2;
                dx/=2;
            for(int k=1;k<4;k++)
            {
                int Y = 2*y[k-1] - dy;
                int X = 2*x[k-1] - dx;
                int ny = X;
                int nx = -Y;
                ny += dy;
                nx += dx;
                y[k] = ny/2;
                x[k] = nx/2;
            }       
            }
            vector <int> v;
            for(int k=0;k<4;k++)
            {
                v.push_back(matrix[y[k]][x[k]] + val);
            }
            for(int k=0;k<4;k++)
            {
                matrix[y[(k+1)%4]][x[(k+1)%4]] = v[k];
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j] -= val;
        }
    }

    return;
    }
};
