int dp[1<<14];
int cnt[26][26];
int cnt2[26];
int tmp[26];

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        memset(cnt,0,sizeof(cnt));
        memset(cnt2,0,sizeof(cnt2));
        for(auto ch : letters)
        {
            cnt2[ch-'a'] += 1;
        }        
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            for(auto ch : words[i])
            {
                cnt[i][ch-'a']+=1;
            }
        }


        memset(dp,-1,sizeof(dp));
        int res = 0;
        dp[0] = 0;

        for(int i=0;i<(1<<n);i++)
        {
            if(dp[i]==-1) continue;
            res = max(res,dp[i]);
            memcpy(tmp,cnt2,sizeof(cnt2));
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j)))
                {
                    for(int k=0;k<26;k++)
                    {
                        tmp[k] -= cnt[j][k];
                    }
                }
            }
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j))) continue;
                int sum = 0;
                bool ok = true;
                for(int k=0;k<26;k++)
                {
                    if(cnt[j][k] > tmp[k])
                    {
                        ok = false;
                        break;
                    }
                    sum += (score[k]*cnt[j][k]);
                }
                if(ok)
                {
                    dp[i + (1<<j)] = max(dp[i +(1<<j)],dp[i] + sum);
                }
            }
        }
        return res;
    }
};
