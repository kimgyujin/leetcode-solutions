class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector <vector<int>> res;
        int n = grid.size();
        int m = grid[0].size();
        for(int y=0;y<=n-k;y++)
        {
            vector <int> tmp;
            for(int x=0;x<=m-k;x++)
            {
                set <int> S;
                vector <int> v;
                for(int i=y;i<y+k;i++)
                {
                    for(int j=x;j<x+k;j++)
                    {
                        S.insert(grid[i][j]);        
                    }
                }
                for(auto it : S) v.push_back(it);
                if(v.size()==1) tmp.push_back(0);
                else
                {
                    int val = v[1] - v[0];
                    for(int i=2;i<v.size();i++)
                    {
                        val = min(val,v[i] - v[i-1]);        
                    }
                    tmp.push_back(val);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
