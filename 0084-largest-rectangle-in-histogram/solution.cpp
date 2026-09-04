int uf[100001];
bool chk[100001];
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
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector <pair<int,int>> v;
        int n = heights.size();
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(heights[i],i));
        }

        sort(v.rbegin(),v.rend());

        int res = 0;

        memset(uf,-1,sizeof(uf));
        memset(chk,false,sizeof(chk));
        for(int i=0;i<n;i++)
        {
            int idx = v[i].second;
            if(idx-1>=0)
            {
                if(chk[idx-1])
                {
                    merge(idx-1,idx);
                }
            }
            if(idx+1<n)
            {
                if(chk[idx+1])
                {
                    merge(idx,idx+1);
                }
            }

            int w = find(idx);
            w = abs(uf[w]);
            //cout << idx << ' ' << w << ' ' << v[i].first << '\n';
            res = max(res,v[i].first*w);
            chk[idx] = true;
        }

        return res;
    }
};
