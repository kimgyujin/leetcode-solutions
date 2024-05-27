class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.length();
        int res = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i+j-1 >= n) break;
                string t = s.substr(i,j);
                int cnt = 0;
                for(int k=1;k<j;k++)
                {
                    if(t[k-1]==t[k])
                    {
                        cnt+=1;
                        if(cnt >= 2) break;
                    }
                }
                if(cnt<=1) res = max(res,j);
            }
        }
        
        return res;
    }
};
