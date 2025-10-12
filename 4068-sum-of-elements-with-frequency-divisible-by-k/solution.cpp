class Solution {
public:
    int cnt[101];
    int sumDivisibleByK(vector<int>& nums, int k) {
        for(auto x : nums) cnt[x]+=1;

        int res = 0;
        for(int i=1;i<=100;i++)
        {
            if(cnt[i]%k==0)
            {
                res += (i*cnt[i]);
            }
        }

        return res;
    }
};
