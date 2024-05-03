// 가지치기

class Solution {
    long long int dp[21];
    vector <string> res;
    int n,m;
    vector <string> words;
    string S;
    void dfs(int idx,string s)
    {
        if(idx==n)
        {
            s.pop_back();
            res.push_back(s);
            return;
        }

        for(int i=0;i<m;i++)
        {
            int k = words[i].length();
            if(idx+k > n) continue;
            if(dp[idx+k]==0) continue;
            if(S.substr(idx,k) == words[i])
            {
                string t = s;
                t += words[i];
                t += ' ';
                dfs(idx+k,t);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        m = wordDict.size();
        memset(dp,0,sizeof(dp));
        dp[n] = 1;
        for(int i=n;i>0;i--)
        {
            if(dp[i]==0) continue;
            for(int j=0;j<m;j++)
            {
                int k = wordDict[j].length();
                if(i-k >= 0 && s.substr(i-k,k) == wordDict[j])
                {
                    dp[i-k] += dp[i];
                }
            }
        }
        
        if(dp[0]==0)
        {
            return res;
        }
        S = s;
        words = wordDict;
        dfs(0,"");
        return res;
    }
};
