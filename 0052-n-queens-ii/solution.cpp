class Solution {
public:
    int dy[4] = {-1,1,1,-1};
    int dx[4] = {1,1,-1,-1};
    int totalNQueens(int n) {
        int res = 0;
        vector <int> perm;

        for(int i=0;i<n;i++) perm.push_back(i);

        do
        {
            set <pair<int,int>> S;
            for(int i=0;i<n;i++) S.insert(make_pair(i,perm[i]));
            bool ok = true;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<4;j++)
                {
                    int y = i;
                    int x = perm[i];
                    while(1)
                    {
                        y += dy[j];
                        x += dx[j];
                        if(y<0 || x<0 || y>=n || x>=n) break;
                        if(S.find(make_pair(y,x))!=S.end())
                        {
                            ok = false;
                            break;
                        }
                    }
                    if(!ok) break;
                }                
                if(!ok) break;
            }
            if(ok) res+=1;
        }while(next_permutation(perm.begin(),perm.end()));

        return res;
    }
};
