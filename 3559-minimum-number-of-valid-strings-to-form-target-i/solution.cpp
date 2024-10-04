class Solution {

    struct Trie
    {
        Trie *go[26];
        Trie *fail;
        bool output;

        Trie()
        {
            fill(go,go+26,nullptr);
            output = false;
        }
        ~Trie()
        {
            for(int i=0;i<26;i++)
            {
                if(go[i])
                {
                    delete go[i];
                }
            }
        }
        void insert(const char* key)
        {
            if(*key=='\0')
            {
                output=true;
                return;
            }
            int next = *key - 'a';
            if(!go[next])
            {
                go[next] = new Trie;
            }
            go[next]->insert(key+1);
        }
    };
    
    public:
    int minValidStrings(vector<string>& words, string target) {
        Trie* root = new Trie;
        for (auto word : words)
        {
            root->insert(word.c_str());
        }
        
        int n = target.length();
        vector <int> dp(n+1,1e9);
        dp[0] = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[i] >= 1e9) continue;
            Trie* now = root;
            for(int j=i;j<n;j++)
            {
                int x = target[j] - 'a';
                if(now->go[x])
                {
                    now = now->go[x];
                    dp[j+1] = min(dp[j+1],dp[i] +1);
                }
                else
                {
                    break;
                }
            }
        }
        if(dp[n] >= 1e9) dp[n] = -1;
        return dp[n];
    }
};
