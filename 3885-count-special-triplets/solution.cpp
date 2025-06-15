class Solution {
    const long long int MOD = 1e9 + 7;
    long long int L[100001];
    long long int R[100001];
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long int res = 0;
        for(int i=0;i<n;i++)
        {
            R[nums[i]]+=1;
        }

        for(int i=0;i<n;i++)
        {
            R[nums[i]]-=1;
            if(2*nums[i] <= 100000)
            {
                long long int ways = L[2*nums[i]];
                ways*=R[2*nums[i]];
                ways%=MOD;
                res += ways;
                res%=MOD;
            }
            L[nums[i]]+=1;
        }
        return res;
    }
};
