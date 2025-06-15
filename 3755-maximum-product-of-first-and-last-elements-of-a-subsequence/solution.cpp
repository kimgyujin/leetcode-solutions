class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long int res = -2e18;
        multiset <long long int, greater<long long int>> P;
        multiset <long long int> N;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(i-m+1 >= 0)
            {
                P.insert(nums[i-m+1]);
                N.insert(nums[i-m+1]);
                long long int A = *(P.begin());
                long long int B = *(N.begin());
                res = max(res,A*nums[i]);
                res = max(res,B*nums[i]);
            }
        }
        return res;
    }
};
