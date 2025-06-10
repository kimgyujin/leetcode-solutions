class Solution {
public:
    int cnt[26];
    int maxDifference(string s) {
        memset(cnt,0,sizeof(cnt));
        int odd = 0;
        int even = 1e9;
        for(auto c : s)
        {
            cnt[c-'a'] += 1;
        }

        for(int i=0;i<26;i++)
        {
            if(cnt[i]==0) continue;
            if(cnt[i]%2==0) even = min(even,cnt[i]);
            else odd = max(odd,cnt[i]);
        }

        return odd - even;
    }
};
