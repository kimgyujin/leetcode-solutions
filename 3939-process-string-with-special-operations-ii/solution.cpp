class Solution {
public:
    char processStr(string s, long long k) {
        
        // 1-index 
        k+=1;
        __int128 len = 0;
        for(auto ch : s)
        {
            if(ch=='*')
            {
                if(len > 0) len-=1;
            }
            else if(ch=='#') len*=2;
            else if(ch>='a' && ch<='z') len+=1;
        }
        if(k > len) return '.';

        reverse(s.begin(),s.end());
        for(auto ch : s)
        {
            if(ch=='*') len+=1;
            else if(ch=='#') 
            {
                if(k > len/2) k-=(len/2);
                len/=2;
            }
            else if(ch=='%') 
            {
                // abcdef
                // k=2
                // reverse => fedcba, k=5
                k = len - k + 1;
            }
            else
            {
                if(len==k) return ch;
                len-=1;
            }
        }
        return '.';
    }
};
