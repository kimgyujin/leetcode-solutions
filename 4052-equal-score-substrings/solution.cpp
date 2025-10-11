class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.length();

        for(int i=0;i<n-1;i++)
        {
            int L = 0;
            int R = 0;
            for(int j=0;j<n;j++)
            {
                if(j<=i) L += (s[j]-'a'+1);
                else R += (s[j]-'a'+1);
            }
            if(L==R) return true;
        }
        return false;
    }
};
