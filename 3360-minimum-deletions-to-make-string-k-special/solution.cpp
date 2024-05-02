class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector <int> cnt(26,0);
        for(auto ch : word)
        {
            cnt[ch-'a'] += 1;
        }        

        int res = 1e9;
        int n = word.length();
        for(int l=0;l<=n;l++)
        {
            int r = l + k;
            int sum = 0;
            for(int i=0;i<26;i++)
            {
                if(cnt[i]==0) continue;
                if(l<=cnt[i] && cnt[i]<=r) continue;
                if(cnt[i] < l)
                {
                    sum += cnt[i];
                }
                else
                {
                    sum += (cnt[i] - r);
                }
            }
            //cout << l << ' ' << r << ' ' << sum << '\n';
            res = min(res,sum);
        }
        return res;
    }
};
