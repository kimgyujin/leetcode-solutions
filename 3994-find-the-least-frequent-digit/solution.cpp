class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int cnt[10];
        memset(cnt,0,sizeof(cnt));

        while(n > 0)
        {
            cnt[n%10] += 1;
            n/=10;
        }

        int res = -1;
        int val = 1e9;
        for(int i=0;i<10;i++)
        {
            if(val > cnt[i] && cnt[i]!=0)
            {
                val = cnt[i];
                res = i;
            }
        }

        return res;
    }
};
