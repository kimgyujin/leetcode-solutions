class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            int cnt[26];
            memset(cnt,0,sizeof(cnt));
            for(int j=i;j<n;j++)
            {
                cnt[s[j]-'a'] += 1;
                bool ok = true;
                for(int k=0;k<26;k++)
                {
                    if(cnt[k]==0) continue;
                    if(cnt[k]!=cnt[s[j]-'a'])
                    {
                        ok = false;
                        break;
                    }
                }
                if(ok) res = max(res,(j-i+1));
            }
        }
        return res;
    }
};
