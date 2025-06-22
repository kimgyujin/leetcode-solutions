class Solution {
    bool isprime[101];
    int cnt[101];
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        memset(isprime,true,sizeof(isprime));
        isprime[0] = false;
        isprime[1] = false;
        for(int i=2;i<=100;i++)
        {
            if(isprime[i])
            {
                for(int j=2*i;j<=100;j+=i) isprime[j] = false;
            }
        }

        for(auto x : nums)
        {
            cnt[x]+=1;
        }

        for(int i=0;i<=100;i++)
        {
            if(isprime[cnt[i]]) return true;
        }
        return false;
    }
};
