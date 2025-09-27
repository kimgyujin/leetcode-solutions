class Solution {
public:
    int cnt[26];
    string S[101];
    string majorityFrequencyGroup(string s) {
        int Max = 0;
        for(auto ch : s)
        {
            cnt[ch-'a'] += 1;
        }
        for(int i=0;i<=100;i++) S[i] = "";
        for(char c='a';c<='z';c++)
        {
            S[cnt[c-'a']] += c;
        }
        string res = "";
        for(int i=100;i>0;i--)
        {
            if(res.length() < S[i].length()) res = S[i];
        }
        return res;
    }
};
