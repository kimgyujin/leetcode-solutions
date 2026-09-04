bool cmp(string a,string b)
{
    if(a.length()==b.length()) return a < b;
    return a.length() < b.length();
}
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        vector <string> res;
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        set <string> S;
        for(int i=0;i<n;i++)
        {
            int m = words[i].length();
            vector <bool> dp(m+1,false);
            dp[0] = true;

            for(int j=0;j<m;j++)
            {
                if(dp[j]==false) continue;
                string t = "";
                for(int k=j;k<m;k++)
                {
                    t += words[i][k];
                    if(S.find(t)!=S.end())
                    {
                        dp[k+1] = true;
                    }
                }
            }

            if(dp[m]) res.push_back(words[i]);

            S.insert(words[i]);
        }

        return res;
    }
};
