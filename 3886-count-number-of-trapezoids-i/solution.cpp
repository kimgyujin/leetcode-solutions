class Solution {
public:
    const long long int MOD = 1e9 + 7;
    map <long long int, long long int> cnt;
    set <long long int> S;
    int countTrapezoids(vector<vector<int>>& points) {
        long long int res = 0;
        long long int sum = 0;
        for(auto p : points)
        {
            S.insert(p[1]);
            cnt[p[1]] += 1;
        }

        for(auto it : S)
        {
            long long int n = cnt[it];
            long long int val = n*(n-1);
            val/=2;
            sum += (val%MOD);
            sum%=MOD;
        }

        for(auto it : S)
        {
            long long int n = cnt[it];
            long long int val = n*(n-1);
            val/=2;
            val%=MOD;
            sum -= (val);
            sum%=MOD;
            if(sum < 0) sum += MOD;
            res += ((val*sum)%MOD);
            res%=MOD;
        }

        return res;
    }
};
