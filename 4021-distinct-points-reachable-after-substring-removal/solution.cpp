class Solution {
public:
    int psum[100005][2];
    int distinctPoints(string s, int k) {
        set <pair<int,int>> S;
        int n = s.length();

        psum[0][0] = 0;
        psum[0][1] = 0;

        for(int i=1;i<=n;i++)
        {
            psum[i][0] = psum[i-1][0];
            psum[i][1] = psum[i-1][1];
            if(s[i-1]=='L') psum[i][0]-=1;
            else if(s[i-1]=='R') psum[i][0]+=1;
            else if(s[i-1]=='U') psum[i][1]+=1;
            else psum[i][1]-=1;
        }

        for(int i=0;i<=n;i++)
        {
            int j = i + k;
            if(j > n) break;
            int x = psum[i][0];
            int y = psum[i][1];
            x += (psum[n][0] - psum[j][0]);
            y += (psum[n][1] - psum[j][1]);
            S.insert(make_pair(x,y));
        }

        return S.size();
    }
};
