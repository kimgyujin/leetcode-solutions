class Solution {
public:
    bool isprime(long long int val)
    {
        if(val==1) return false;
        long long int m = sqrt(val);
        for(int j=2;j<=m;j++)
        {
            if(val%j==0) return false;
        }
        return true;
    }
    
    long long sumOfLargestPrimes(string s) {
        set <long long int> S;
        vector <long long int> v;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            long long int val = 0;
            for(int j=i;j<n;j++)
            {
                val = 10*val + (s[j] - '0');
                if(isprime(val)) S.insert(val);
            }
        }
        
        for(auto it : S) v.push_back(it);
        long long int res = 0;
        sort(v.rbegin(),v.rend());
        int N = v.size();
        for(int i=0;i<min(N,3);i++)
        {
            res += v[i];
        }
        
        return res;
    }
};
